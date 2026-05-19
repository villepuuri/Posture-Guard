# GATT SensorData sample (gatt_sensordata_app)

This firmware implements a simple request/response protocol on top of Bluetooth GATT datapipe (tx/rx). The purpose of this sample was to provide an alternate way to access Movesense sensor datastreams from devices that do not have MDS library. This includes laptops and other computers as well as microcontroller boards.

## Clients

The sample includes examples of client codes using Python 3.x with Bleak library as well as HTML + JavaScript (WebBLE -API). The datastreams are returned in a binary format using the code generated for DataLogger/Logbook. For exact format, see the generated source files under build folder at *<build_folder>/generated/sbem-code*.

## Overridden by official GSP (Gatt SensorData Protocol)

Starting in Movesense MD firmware 1.0 and Movesense device library 2.3.0, expanded version of this protocol has been made an official part of Movesense sensor offernings. The protocol is called GSP ("GATT SensorData Protocol") and it is included as a part of Movesense default firmware (>= 2.3.0) as well as Movesense MD firmware (>= 1.0). The documentation of the GSP protocol can be found [here](https://movesense.com/docs/esw/gatt_sensordata_protocol/).

## What it does:
 * Creates a GATT service with two characteristics (tx: NOTIFY, rx: WRITE)
 * Simple command protocol 
 * subscription to Movesense datastreams using the API path
   * data serialization using DataLogger's serialization code

## APIs defined

None