import 'dart:async';
import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:mdsflutter/Mds.dart';
import 'package:posture_guard/features/ble_connection/presentation/reset_base_angle_dialog.dart';
import 'package:posture_guard/features/ble_connection/services/sensor.dart';
import 'package:vibration/vibration.dart';

class DataPage extends StatefulWidget {
  const DataPage({super.key});

  @override
  State<DataPage> createState() => _DataPageState();
}

class _DataPageState extends State<DataPage> {
  Timer? _timer;
  Timer? _showInfoTimer;
  final int updateInterval = 4;
  Sensor? _sensor;
  int _angleValue = 0;
  double _fontSize = 20;
  int? debugSubscriptionId;
  bool _initialized = false;

  // Base angles
  int? _baseAngle;
  bool _invertAngles = false;

  @override
  void didChangeDependencies() {
    super.didChangeDependencies();

    if (!_initialized) {
      _sensor = ModalRoute.of(context)!.settings.arguments as Sensor;

      _startTimer();
      // debugSubscriptionId = _startDebugLogger();

      WidgetsBinding.instance.addPostFrameCallback((_) {
        setBaseAngle();
      });

      _initialized = true;
    }
  }

  @override
  void dispose() {
    _timer?.cancel();
    if (debugSubscriptionId != null) {
      Mds.unsubscribe(debugSubscriptionId!);
    }
    super.dispose();
  }

  void _startTimer() {
    _timer = Timer.periodic(Duration(seconds: updateInterval), (Timer t) {
      _executeTask();
    });
  }

  /// Set the base angle and if angles need to be inverted
  void setBaseAngle() {
    showDialog(
      context: context,
      builder: (BuildContext dialogContext) {
        return ResetBaseAngleDialog(
          getPostureAngle: _getPostureAngle,
          returnValues: (int baseAngle, bool inverted) {
            _baseAngle = baseAngle;
            _invertAngles = inverted;
          },
        );
      },
    );
  }

  int _startDebugLogger() {
    return Mds.subscribe(
      Mds.createSubscriptionUri(_sensor!.serial, "/System/Debug/Info"),
      "{}",
      (String s, int i) {
        debugPrint('DEBUG SUB SUCCESS: $s, $i');
        // onSuccess
      },
      (String s, int i) {
        // onError
        debugPrint('DEBUG SUB ERROR: $s, $i');
      },
      (String message) {
        // onNotification
        final data = jsonDecode(message);

        if (data["Body"] != null) {
          debugPrint('BODY: ${data["Body"]["Message"]}');
        }
      },
      (String s, int i) {
        // onSubscriptionError
        debugPrint('DEBUG ERROR: $s, $i');
      },
    );
  }

  /// Map an angle value to get the font size accordingly
  double _mapValue(
    int angle,
    int minAngle,
    int maxAngle,
    double minFontSize,
    double maxFontSize,
  ) {
    return minFontSize +
        ((angle - minAngle) *
            (maxFontSize - minFontSize) /
            (maxAngle - minAngle));
  }

  Future<void> _executeTask() async {
    int? angleValue = await _getPostureAngle();
    if (angleValue != null && _baseAngle != null) {
      setState(() {
        _angleValue = angleValue! - _baseAngle!;
        if (_invertAngles) {
          _angleValue *= -1;
        }
      });


      // Based on the angle value, set the fontSize and vibration
      int firstAngleLimit = 10;
      int secondAngleLimit = 20;

      angleValue = _angleValue;
      if (angleValue < 0) {
        angleValue *= -1;
      }

      if (angleValue <= firstAngleLimit) {
        _fontSize = _mapValue(angleValue, 0, firstAngleLimit, 50, 60);
      } else if (angleValue > firstAngleLimit &&
          angleValue <= secondAngleLimit) {
        _fontSize = _mapValue(
          angleValue,
          firstAngleLimit,
          secondAngleLimit,
          60,
          120,
        );
        Vibration.vibrate(pattern: [10, 200]);
      } else {
        _fontSize = 120;
        Vibration.vibrate(pattern: [10, 200, 50, 400, 200, 400, 200, 100]);
      }
    }
  }

  /// Get the value from the sensor
  Future<int?> _getPostureAngle() async {
    final completer = Completer<int?>();

    Mds.get(
      Mds.createRequestUri(_sensor!.serial, "/Custom/PostureService"),
      "{}",
      (result, code) {
        int? angle = jsonDecode(result)["Content"];
        completer.complete(angle);
      },
      (result, code) {
        debugPrint('Error: $result');
        completer.completeError(result);
      },
    );
    return completer.future;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 40),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.end,
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            AnimatedDefaultTextStyle(
              duration: const Duration(milliseconds: 300),
              curve: Curves.easeInOut,
              style: Theme.of(
                context,
              ).textTheme.titleLarge!.copyWith(fontSize: _fontSize),
              child: Text("${_angleValue.toString()}°"),
            ),
          ],
        ),
      ),
    );
  }
}
