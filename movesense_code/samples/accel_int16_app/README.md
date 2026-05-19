# Accelerometer as 16-bit integers (accel_int16_app)

This sample demonstrates the creation of a data format conversion service and custom location for the API .yaml-files.

## What it does:
 * Provides a datastream of accelerometer samples as int16 fixed-point values

## APIs defined

### /Sample/IntAcc/{SampleRate} \[SUBSCRIBE\]

Provides a datastream similar to /Meas/Acc/{SampleRate}, but acceleration samples as fixed-point int16 values [See the API](service-api-spec/IntegerAccelerometerService.yaml).