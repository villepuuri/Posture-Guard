import 'package:flutter/material.dart';
import 'package:posture_guard/core/theme.dart';
import 'package:posture_guard/features/general/presentation/welcome_page.dart';
import 'package:posture_guard/features/data_exchage/data_page.dart';

import 'features/ble_connection/presentation/connect_sensor.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: AppThemeData.darkTheme,
      routes: {
        '/': (context) => const WelcomePage(),
        '/sensor_page': (context) => const ConnectSensor(),
        '/data_page': (context) => const DataPage(),
      },
    );
  }
}
