# Standard BLE Services sample (ble_std_services)

This sample shows how to provide Bluetooth SIGs "HRS" profile and Nordic Semiconductors "NrfUART" profile on the sensor.

## What it does:
 * In startup, subscribes to:
   * /Comm/Ble/Peers to see connect/disconnect events
   * HRS module notifications (HRS notifications enabled)
   * UART module notifications (data received)
 * When HRS notifications are enabled, subscribe to /Meas/HR, and send data to HRS module
 * When there is no bluetooth connection, run timer with LED blinks and after 60 seconds, shut-down the sensor with stud wakeup (simplified version of Default_firmware logic).

## APIs defined

None