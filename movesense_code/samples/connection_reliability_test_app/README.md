# Connection Reliability tester app (connection_reliability_test_app)

This firmware provides a way to get a data stream of incrementing numbers, that can be used to notice missing notifications

## What it does:

* Provides a notification resource that when subscribed, gives notifications with incrementing numbers every 100 ms.

## APIs defined

### /Test/ConnectionReliability/IncrementSmallPkg \[SUBSCRIBE\]

Returns small notification packets with incremented content (single uint32).


### /Test/ConnectionReliability/IncrementLargePkg \[SUBSCRIBE\]

Returns large notification packets with incremented content (16x uint32).