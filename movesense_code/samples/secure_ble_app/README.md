# Secure BLE sample (secure_ble_app)

This sample is modified from hr_wakeup_app/ble_std_services with the addition of marking the Whiteboard BLE connection as requiring BLE Bonding and encryption. See macro *BLE_REQUIRE_BONDING(true)* in *App.cpp* -file.

## What it does:
 * Starts a timer that blinks LED
 * subscribes to stud connector state and Whiteboard route table
 * If no WB connection or stud contact or DataLogger active, sets up stud wakeup and puts the sensor to FullPowerOff mode
 * When Whiteboard BLE connection is done, Bluetooth bonding flow is triggered.

## APIs defined

None