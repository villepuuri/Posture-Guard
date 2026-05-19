# Dual BLE sample (dual_ble_app)

This sample shows how to configure the Movesense sensor to support two simultaneous BLE connections (such as Movesense showcase app and smart watch).

## What it does:
 * Configures Dual BLE mode in App.cpp with *MOVESENSE_BLE_CONFIG_2PERIPHERALS* -macro.
 * Uses *BleStandardHRS* -module to provide heart rate over standard HRS profile (see: *ble_std_services* -sample). 

## APIs defined

None