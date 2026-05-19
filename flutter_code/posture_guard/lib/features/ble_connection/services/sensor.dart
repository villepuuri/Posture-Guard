import 'package:flutter/material.dart';

enum SensorState { disconnected, disabled, connecting, connected, other }

class Sensor {
  final String name;
  final String address;
  SensorState? state;

  Sensor({required this.name, required this.address, SensorState? state})
    : state = state ?? SensorState.disconnected;

  String? get id => serial;

  /// Get the number serial code from the name
  String get serial {
    RegExp numberExpression = RegExp(r'(\d+)');
    RegExpMatch? match = numberExpression.firstMatch(name);
    if (match == null) {
      debugPrint('Serial number not found');
      return name;
    }
    return match[0] ?? name;
  }

  void setState(SensorState newState) => state = newState;

  @override
  String toString() {
    return "$name, $address, $serial";
  }

  @override
  bool operator ==(Object other) {
    if (identical(this, other)) return true;

    return other is Sensor && other.name == name && other.address == address;
  }

  @override
  int get hashCode => address.hashCode ^ name.hashCode;
}
