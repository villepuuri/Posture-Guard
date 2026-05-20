import 'dart:async';
import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:mdsflutter/Mds.dart';
import 'package:posture_guard/features/ble_connection/services/sensor.dart';

class DataPage extends StatefulWidget {
  const DataPage({super.key});

  @override
  State<DataPage> createState() => _DataPageState();
}

class _DataPageState extends State<DataPage> {
  Timer? _timer;
  final int updateInterval = 4;
  Sensor? _sensor;
  int value = 0;
  int? debugSubscriptionId;
  bool _initialized = false;

  @override
  void didChangeDependencies() {
    super.didChangeDependencies();

    if (!_initialized) {
      _sensor = ModalRoute.of(context)!.settings.arguments as Sensor;

      _startTimer();
      // debugSubscriptionId = _startDebugLogger();

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

  Future<void> _executeTask() async {
    // value = Random().nextInt(100);

    Mds.get(
      Mds.createRequestUri(_sensor!.serial, "/Custom/PostureService"),
      "{}",
      (result, code) {
        print(result);
        setState(() {
          value = jsonDecode(result)["Content"];
        });
      },
      (result, code) {
        debugPrint('Error: $result');
      },
    );
  }

  @override
  Widget build(BuildContext context) {

    /// Map an angle value to get the font size accordingly
    double mapValue(angle, minAngle, maxAngle, minFontSize, maxFontSize) {
      return minFontSize +
          ((angle - minAngle) *
              (maxFontSize - minFontSize) /
              (maxAngle - minAngle));
    }

    /// Returns a font size for the angle value based on the angle value deflection
    double getFontSize(int angleValue) {
      double firstAngleLimit = 20;
      double secondAngleLimit = 40;
      double thirdAngleLimit = 60;

      if (angleValue < 0) {
        angleValue *= -1;
      }

      if (angleValue <= firstAngleLimit) {
        return mapValue(angleValue, 0, firstAngleLimit, 50, 60);
      } else if (angleValue > firstAngleLimit &&
          angleValue <= secondAngleLimit) {
        return mapValue(angleValue, firstAngleLimit, secondAngleLimit, 60, 85);
      } else if (angleValue > secondAngleLimit &&
          angleValue <= thirdAngleLimit) {
        return mapValue(angleValue, secondAngleLimit, thirdAngleLimit, 85, 120);
      } else {
        return 120;
      }
    }

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
              ).textTheme.titleLarge!.copyWith(fontSize: getFontSize(value)),
              child: Text("${value.toString()}°"),
            ),
          ],
        ),
      ),
    );
  }
}
