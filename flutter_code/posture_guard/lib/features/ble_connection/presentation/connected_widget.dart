import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:mdsflutter/Mds.dart';

import '../services/sensor.dart';

class ConnectedWidget extends StatefulWidget {
  final Sensor sensor;
  final Function onDisconnect;

  const ConnectedWidget({
    super.key,
    required this.sensor,
    required this.onDisconnect,
  });

  @override
  State<ConnectedWidget> createState() => _ConnectedWidgetState();
}

class _ConnectedWidgetState extends State<ConnectedWidget> {
  int? batteryLevel;

  @override
  void initState() {
    super.initState();

    getBatteryStatus();
  }

  Future<void> getBatteryStatus() async {
    Mds.get(
      Mds.createRequestUri(widget.sensor.serial, "/System/Energy/Level"),
      "{}",
      (result, code) {
        print(result);
        batteryLevel = jsonDecode(result)["Content"];
        setState(() {});
      },
      (result, code) {
        debugPrint('Error: $result');
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.end,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        InkWell(
          onTap: () {
            Mds.get(
              Mds.createRequestUri(widget.sensor.serial, "/Info"),
              "{}",
              (data, status) {
                // onSuccess
                Map<String, dynamic> sensorInfo = jsonDecode(data);
                final content = sensorInfo["Content"] as Map<String, dynamic>;

                showDialog(
                  context: context,
                  builder: (context) {
                    return AlertDialog(
                      title: const Text("Device Info"),
                      content: SizedBox(
                        width: double.maxFinite,
                        child: SingleChildScrollView(
                          child: Column(
                            crossAxisAlignment: CrossAxisAlignment.start,
                            children: [
                              ...content.entries.map((e) {
                                if (e.value is List) {
                                  return Text(
                                    "${e.key}: ${(e.value as List).map((i) => i.toString()).join(", ")}",
                                  );
                                }
                                return Padding(
                                  padding: const EdgeInsets.symmetric(
                                    vertical: 2,
                                  ),
                                  child: Text("${e.key}: ${e.value ?? "N/A"}"),
                                );
                              }),
                            ],
                          ),
                        ),
                      ),
                      actions: [
                        TextButton(
                          onPressed: () => Navigator.pop(context),
                          child: const Text("Close"),
                        ),
                      ],
                    );
                  },
                );
              },
              (reason, status) {
                // onError
                debugPrint('ERROR $status: $reason');
              },
            );
          },
          child: Text(
            "Movesense ${widget.sensor.serial}",
            style: Theme.of(context).textTheme.headlineMedium,
          ),
        ),
        const SizedBox(height: 5),
        Text(
          batteryLevel != null ? "Battery  $batteryLevel %" : "",
          style: Theme.of(context).textTheme.bodyMedium,
        ),

        const SizedBox(height: 20),

        TextButton(
          onPressed: () {
            Mds.disconnect(widget.sensor.address);
            debugPrint('Disconnected');
            widget.sensor.setState(SensorState.disconnected);
            widget.onDisconnect();
          },
          child: Text("Disconnect"),
        ),

        const SizedBox(height: 30),

        TextButton(
          onPressed: () {
            debugPrint('Moving to the data page with sensor: ${widget.sensor}');
            Navigator.pushNamed(
              context,
              '/data_page',
              arguments: widget.sensor,
            );
          },
          child: Icon(Icons.arrow_forward, size: 28),
        ),
      ],
    );
  }
}
