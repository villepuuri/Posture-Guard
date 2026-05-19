# OneWire sample app (1wire_app)

This sample firmeware demonstrates the use of 1-Wire bus via Movesense API. This sample works correctly only in the Movesense sensor with 1-wire support (currently only *Movesense HR+*).

**NOTE**: This sample works correctly only in the Movesense sensor with 1-wire support (currently only *Movesense HR+*).


## What it does:

* starts timer that performs operation every 10 seconds
* for each operation:
    * Scan the 1Wire bus for devices
        * If no Smart connectors found, skip the rest
        * For Smart connector, read the ScrathPad memory content
* while "Movesense SmartConnector" is connected the app enables double tap detection
    * for double tap the app writes bytes [1,2,3,4] to the smart connectors memory

## APIs defined

This firmware does not define any new APIs.