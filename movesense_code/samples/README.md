# Movesense Sample applications
===================

![Movesense](http://ultramabouls.com/wp-content/uploads/2017/01/Movesense.jpg)

This README file explains how to build use the Movesense sensor firmware samples. Each firmware is a "Movesense app" that is built with the standard Movesense sensor framework. Also each app includes some of the optional Movesense framework modules as a part of the build process. Those are defined with the *OPTIONAL_CORE_MODULE(<module_name>)* -macros in the firmwares *App.cpp* -file. 

## Sample firmware APIs

If the sample implements a new Movesense service ("ResourceProvider"), the APIs are defined in the *wbresources* -subfolder. The build process reads the API-definition yaml files and generates code that the firmware app uses. If the service data is compatible with the DataLogger (see: https://www.movesense.com/docs/esw/data_storage/#datalogger-service), the serialization code is generated as a part of the build process, and included in the firmware. The serialization code can be found in the *<build_folder>/generated/sbem_code*.

## Building and running

To build the sample application, a build folder is needed. There is no limitation on the location or number of build folders, so use a location that is convenient to you. The hardware target builds (firmware meant for physical Movesense sensor) use a [containerized build environment running on docker](https://www.movesense.com/docs/esw/getting_started/#build-commands-real-hw). This document assumes that the build folder is created on the top level of the Movesense-device-lib folder (the one with *MovesenseCoreLib* and *samples* folders).

```
mkdir _my_build_folder
cd _my_build_folder
```

### Generating build files
The next step is to generate the Ninja build files using the CMake tool. Here the firmware application is specified as well as the location of the Movesense SDK folder (*MovesenseCoreLib*). 

```cmake -G "Ninja" -DMOVESENSE_CORE_LIBRARY=../MovesenseCoreLib/ -DCMAKE_TOOLCHAIN_FILE=../MovesenseCoreLib/toolchain/gcc-nrf52.cmake ../samples/blinky_app```


### Building the firmware

After the build folder has been initialized with the CMake, the firmware can be built with the following command:

```ninja pkgs```

This builds the firmware and places the resulting firmware flashing file (*Movesense_combined.hex*, used to flash the sensor with the programming jig) and DFU package (*Movesense_dfu_w_bootloader.zip*, for updating sensor over Bluetooth) files in the build folder.
