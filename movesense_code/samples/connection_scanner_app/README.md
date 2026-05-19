# Connection Scanner sample (connection_scanner_app)

This firmware shows how to detect simple stud contact (using /System/States -API), 1-wire devices (using /Misc/Gear/ID -API) and HR data (/Meas/HR). It also demonstrates a simple implementation of a state machine based on different events.

## What it does:
 * Subscribes to stud contact detection at startup
 * When connection is detected, try to read Gear ID
 * If no Gear, subscribe to HR to see if there is HR signal

## APIs defined

None