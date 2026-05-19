# Custom GATT Service sample (custom_gattsvc_app)

This sample shows how to create and use a custom GATT service on the sensor. As an example, this creates a "Medical Thermometer" service, that uses the sensor built-in temperature sensor.

**NOTE**: The temperature value only available on sensors that contain the internal temperature sensor: Movesense HR+, MD and Flash.

## What it does:
 * At startup, creates the GATT service using the "CustomGattService" -module.
 * When GATT Service is created, read the configuration back and subscribe to each characteristics events.
 * When client changes the interval characteristic, start/restart timer and
   * On timer, read temperature value and change temperature characteristic.

## APIs defined

None