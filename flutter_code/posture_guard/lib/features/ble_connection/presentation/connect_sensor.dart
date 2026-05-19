import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:mdsflutter/Mds.dart';
import 'package:posture_guard/features/ble_connection/presentation/connected_widget.dart';
import 'package:posture_guard/features/ble_connection/presentation/searching_and_connecting_widget.dart';
import 'package:posture_guard/features/ble_connection/services/sensor.dart';

class ConnectSensor extends StatefulWidget {
  const ConnectSensor({super.key});

  @override
  State<ConnectSensor> createState() => _ConnectSensorState();
}

class _ConnectSensorState extends State<ConnectSensor> {
  Sensor? selectedSensor;

  @override
  void initState() {
    super.initState();

    checkConnectedDevices();
  }

  void checkConnectedDevices() {
    Mds.get("suunto://MDS/ConnectedDevices", "{}", (response, code) {
      List<dynamic> devices = jsonDecode(response)["Devices"];
      print(response);
      if (devices.isNotEmpty) {
        String deviceSerial = devices.first.toString();
        debugPrint('One device is already connected: $deviceSerial');
        // todo: get also the address here

        Map<String, dynamic> connectedData = jsonDecode(response)[deviceSerial];
        String deviceAddress =
            connectedData["DeviceInfo"]["addressInfo"].first["address"];

        selectedSensor = Sensor(
          name: deviceSerial,
          address: deviceAddress,
          state: SensorState.connected,
        );
        setState(() {});
      } else {
        debugPrint('There are not any connected devices');
      }
    }, (response, code) {});
  }

  @override
  Widget build(BuildContext context) {
    Widget buildBody() {
      if (selectedSensor != null &&
          selectedSensor?.state == SensorState.connected) {
        // A sensor is connected
        return ConnectedWidget(
          sensor: selectedSensor!,
          onDisconnect: () {
            // Return to the home page
            Navigator.pop(context);
          },
        );
      } else {
        // The sensor is not null
        return SearchingAndConnectingWidget(
          onStopScanning: () {
            selectedSensor = Sensor(name: "", address: "");
            setState(() {});
          },
          onConnected: (Sensor sensor) {
            selectedSensor = sensor;
            setState(() {});
          },
          onDisconnected: () {
            debugPrint('Sensor disconnected');
            selectedSensor = null;
          },
        );
      }
    }

    return Scaffold(
      appBar: AppBar(),
      body: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 40),
        child: buildBody(),
      ),
    );
  }
}
