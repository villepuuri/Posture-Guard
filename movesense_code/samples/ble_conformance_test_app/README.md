# BLE Conformance Test app (ble_conformance_test_app)

This firmware provides a way to put sensor in different BLE radio test modes, such as transmitter and receiver tests as described in the nRF52 Component API.

## What it does:
 * Provides a way to command sensor in ble test modes to perform bluetooth radio testing

## APIs defined

### /BleConformance \[PUT\]

Each PUT request puts the sensor in a test mode for the time given in timeout -parameter. After timeout, the sensor is accessable again.