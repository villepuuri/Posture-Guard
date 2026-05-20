import 'package:flutter/material.dart';
import 'package:mdsflutter/Mds.dart';
import 'package:permission_handler/permission_handler.dart';

import '../services/sensor.dart';

class SearchingAndConnectingWidget extends StatefulWidget {
  final VoidCallback? onStopScanning;
  final Function onConnected;
  final VoidCallback onDisconnected;

  const SearchingAndConnectingWidget({
    super.key,
    required this.onStopScanning,
    required this.onConnected,
    required this.onDisconnected,
  });

  @override
  State<SearchingAndConnectingWidget> createState() =>
      _SearchingAndConnectingWidgetState();
}

class _SearchingAndConnectingWidgetState
    extends State<SearchingAndConnectingWidget> {
  List<Sensor> foundDevices = [];

  @override
  void initState() {
    super.initState();

    startSearchingSensors();
  }

  Future<void> startSearchingSensors() async {
    // Firstly check the required Bluetooth permissions
    debugPrint('Asking permissions...');
    bool result = await requestBluetoothPermissions();
    if (!result) {
      debugPrint('Permissions are denied');
      return;
    } else {
      debugPrint('Permissions are granted');
    }

    // Start scanning for devices
    debugPrint('Scanning started...');
    Mds.startScan((name, address) {
      // Check that the address is a proper one
      if (name != null && address != null) {
        Sensor foundSensor = Sensor(name: name, address: address);
        if (!foundDevices.any((sensor) => sensor == foundSensor)) {
          debugPrint('Movesense found! $foundSensor');
          foundDevices.add(foundSensor);
          setState(() {});
        } else {
          debugPrint('Found the same movesense: $name');
        }
      }
    });
  }

  void connectToMovesense(Sensor sensor) {
    debugPrint('Connecting to...');
    Mds.connect(
      sensor.address,
      (serial) {
        sensor.setState(SensorState.connected);
        widget.onConnected(sensor);
      },
      () {
        // onDisconnected
        debugPrint('Sensor disconnected');
        for (Sensor s in foundDevices) {
          s.setState(SensorState.disconnected);
        }
        setState(() {});
      },
      (error) {
        // onConnectionError
        for (Sensor s in foundDevices) {
          s.setState(SensorState.disconnected);
        }
        setState(() {});
      },
      (some) {
        // onBleConnected
        debugPrint('BLE connected, I do not know what that means');
      },
    );
  }

  Future<bool> requestBluetoothPermissions() async {
    final statuses = await [
      Permission.bluetoothScan,
      Permission.bluetoothConnect,
      Permission.location,
    ].request();

    if (statuses[Permission.bluetoothScan]!.isGranted &&
        statuses[Permission.bluetoothConnect]!.isGranted &&
        statuses[Permission.location]!.isGranted) {
      return true;
      // Permissions granted
    } else {
      // Handle denied
      return false;
    }
  }

  bool get isSomeSensorConnecting {
    for (Sensor s in foundDevices) {
      if (s.state == SensorState.connecting) {
        return true;
      }
    }
    return false;
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.end,
      crossAxisAlignment: CrossAxisAlignment.start,
      children:
          foundDevices
              .map<Widget>(
                (sensor) => ListTile(
                  title: Text(sensor.name),
                  contentPadding: const EdgeInsets.symmetric(vertical: 5),
                  enabled: sensor.state != SensorState.disabled,
                  trailing: sensor.state == SensorState.connecting
                      ? CircularProgressIndicator(
                          color: Theme.of(context).colorScheme.primary,
                        )
                      : sensor.state != SensorState.disabled
                      ? IconButton(
                          onPressed: () {
                            // Stop the scan
                            Mds.stopScan();
                            debugPrint('Scanning stopped');

                            // Set others to disabled and this to connecting
                            sensor.setState(SensorState.connecting);
                            for (Sensor s in foundDevices) {
                              if (s != sensor) {
                                s.setState(SensorState.disabled);
                              }
                            }
                            setState(() {});

                            // Connect to a sensor and change the widget
                            connectToMovesense(sensor);
                          },
                          icon: Icon(Icons.arrow_forward),
                        )
                      : null,
                ),
              )
              .toList() +
          [
            const SizedBox(height: 20),

            !isSomeSensorConnecting
                ? LinearProgressIndicator(
                    color: Theme.of(context).colorScheme.primary,
                    backgroundColor: Colors.transparent,
                  )
                : SizedBox(),
            TextButton(
              onPressed: () {
                Mds.stopScan();
                debugPrint('User stopped the scanning');
                Navigator.pop(context);
              },
              child: Text("Stop"),
            ),
          ],
    );
  }
}
