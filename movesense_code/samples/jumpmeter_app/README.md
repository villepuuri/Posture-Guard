# Jump-meter app (jump_meter_app)

This sample demonstrates a creation of a service that calculates a derived information (in this case jump height) from accelerometer data. When the jump height resource is subscribed, accelerometer is subscribed. For each accelerometer sample G-value is calculated and if sensor is in zero-G (=free fall), jump is detected (Note: jumps are best detected when throwing the sensor in the air).

## What it does:

* Provides a resource for detected jumps

## APIs defined

### /Sample/JumpCounter/JumpCount \[GET, SUBSCRIBE\]

Gives and notifies with current jump count when new jump is detected or GET is performed

### /Sample/JumpCounter/LastJumpHeight \[GET, SUBSCRIBE\]

Gives and notifies with last measured jump height every time a new jump is detected or GET is performed.
