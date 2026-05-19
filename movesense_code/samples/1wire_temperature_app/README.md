# OneWire external temperature sensor reader (1wire_temperature_app)

This sample demonstrates the use of 1-Wire bus with an external 1.8 volt 1-wire temperature sensor, such as MAX30207 or MAX31888.

**NOTE**: This sample works correctly only in the Movesense sensor with 1-wire support (currently only *Movesense HR+*).

## What it does:

* for each GET to /Sample/1WireTemp:
    *  activate 1Wire bus
    *  Scan the 1Wire bus for devices
    *  For each device with THERMOMETER_FAMILY_CODE:
        * start temperature measurement, read the value
    *  Return result containing all the temperature values

## APIs defined

### /Sample/1WireTemp \[GET\]

Returns an array of all temperature sensors attached to the 1-wire bus and their temperature readings in Kelvin. [See the API](wbresources/1WireTemperature.yaml).