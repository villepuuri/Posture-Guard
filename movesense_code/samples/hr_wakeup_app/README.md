# HR Wakeup sample (hr_wakeup_app)

This sample shows how the sensor can be set for stud contact wakeup and how to put the sensor to "FullPowerOff" mode.

## What it does:
 * Starts a timer that blinks LED
 * subscribes to stud connector state and Whiteboard route table, and reads DataLogger state
 * If no WB connection or stud contact or DataLogger active, sets up stud wakeup and puts the sensor to FullPowerOff mode

## APIs defined

None