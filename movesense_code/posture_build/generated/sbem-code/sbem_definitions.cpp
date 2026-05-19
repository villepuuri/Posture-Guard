#include "whiteboard/Value.h"
#include "app-resources/resources.h"
#include "component_max3000x/resources.h"
#include "comm_ble_gattsvc/resources.h"
#include "system_settings/resources.h"
#include "meas_gyro/resources.h"
#include "comm_1wire/resources.h"
#include "system_mode/resources.h"
#include "meas_acc/resources.h"
#include "component_led/resources.h"
#include "mem_logbook/resources.h"
#include "meas_magn/resources.h"
#include "system_energy/resources.h"
#include "ui_ind/resources.h"
#include "system_memory/resources.h"
#include "device_systemevent/resources.h"
#include "comm_ble_hrs/resources.h"
#include "movesense_types/resources.h"
#include "meas_imu/resources.h"
#include "dev_system/resources.h"
#include "misc_manufacturing/resources.h"
#include "system_debug/resources.h"
#include "component_nrf52/resources.h"
#include "component_ds24l65/resources.h"
#include "device_system_debug/resources.h"
#include "meas_temp/resources.h"
#include "misc_calibration/resources.h"
#include "device_system_shutdown/resources.h"
#include "comm_ble_nus/resources.h"
#include "meas_hr/resources.h"
#include "component_eeprom/resources.h"
#include "component_lsm6ds3/resources.h"
#include "meas_ecg/resources.h"
#include "misc_gear/resources.h"
#include "comm_ble/resources.h"
#include "system_states/resources.h"
#include "mem_datalogger/resources.h"
#include "movesense_time/resources.h"
#include "movesense_info/resources.h"
#include "wb-resources/resources.h"
#include "sbem_definitions.h"

CREATE_GROUP(MEASACC_ARRAYACC_,
    static_cast<uint16_t>(MEASACC_ARRAYACC_X),
    static_cast<uint16_t>(MEASACC_ARRAYACC_Y),
    static_cast<uint16_t>(MEASACC_ARRAYACC_Z));

CREATE_GROUP(MEASACC_1,
    static_cast<uint16_t>(MEASACC_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASACC_2,
    static_cast<uint16_t>(MEASACC_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASACC_4,
    static_cast<uint16_t>(MEASACC_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASACC_8,
    static_cast<uint16_t>(MEASACC_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(MEASACC_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASECG_16,
    static_cast<uint16_t>(MEASECG_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(MEASECG_SAMPLES),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASECGMV_16,
    static_cast<uint16_t>(MEASECGMV_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(MEASECGMV_SAMPLES),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASGYRO_ARRAYGYRO_,
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_X),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_Y),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_Z));

CREATE_GROUP(MEASGYRO_1,
    static_cast<uint16_t>(MEASGYRO_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASGYRO_2,
    static_cast<uint16_t>(MEASGYRO_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASGYRO_4,
    static_cast<uint16_t>(MEASGYRO_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASGYRO_8,
    static_cast<uint16_t>(MEASGYRO_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(MEASGYRO_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASHR_1,
    static_cast<uint16_t>(MEASHR_AVERAGE),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASHR_2,
    static_cast<uint16_t>(MEASHR_AVERAGE),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASHR_3,
    static_cast<uint16_t>(MEASHR_AVERAGE),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASHR_4,
    static_cast<uint16_t>(MEASHR_AVERAGE),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASHR_5,
    static_cast<uint16_t>(MEASHR_AVERAGE),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASHR_6,
    static_cast<uint16_t>(MEASHR_AVERAGE),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASHR_7,
    static_cast<uint16_t>(MEASHR_AVERAGE),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASHR_8,
    static_cast<uint16_t>(MEASHR_AVERAGE),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(MEASHR_RRDATA),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU6_ARRAYACC_,
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_X),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_Y),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_Z));

CREATE_GROUP(MEASIMU6_ARRAYGYRO_,
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_X),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_Y),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_Z));

CREATE_GROUP(MEASIMU6_1,
    static_cast<uint16_t>(MEASIMU6_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU6_2,
    static_cast<uint16_t>(MEASIMU6_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU6_4,
    static_cast<uint16_t>(MEASIMU6_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU6_8,
    static_cast<uint16_t>(MEASIMU6_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU6_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU6M_ARRAYACC_,
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_X),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_Y),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_Z));

CREATE_GROUP(MEASIMU6M_ARRAYMAGN_,
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_X),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_Y),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_Z));

CREATE_GROUP(MEASIMU6M_1,
    static_cast<uint16_t>(MEASIMU6M_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU6M_2,
    static_cast<uint16_t>(MEASIMU6M_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU6M_4,
    static_cast<uint16_t>(MEASIMU6M_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU6M_8,
    static_cast<uint16_t>(MEASIMU6M_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU6M_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU9_ARRAYACC_,
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_X),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_Y),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_Z));

CREATE_GROUP(MEASIMU9_ARRAYGYRO_,
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_X),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_Y),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_Z));

CREATE_GROUP(MEASIMU9_ARRAYMAGN_,
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_X),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_Y),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_Z));

CREATE_GROUP(MEASIMU9_1,
    static_cast<uint16_t>(MEASIMU9_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU9_2,
    static_cast<uint16_t>(MEASIMU9_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU9_4,
    static_cast<uint16_t>(MEASIMU9_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASIMU9_8,
    static_cast<uint16_t>(MEASIMU9_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(MEASIMU9_ARRAYACC_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(MEASIMU9_ARRAYGYRO_),
    static_cast<uint16_t>(ARRAY_END),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(MEASIMU9_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASMAGN_ARRAYMAGN_,
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_X),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_Y),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_Z));

CREATE_GROUP(MEASMAGN_1,
    static_cast<uint16_t>(MEASMAGN_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASMAGN_2,
    static_cast<uint16_t>(MEASMAGN_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASMAGN_4,
    static_cast<uint16_t>(MEASMAGN_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASMAGN_8,
    static_cast<uint16_t>(MEASMAGN_TIMESTAMP),
    static_cast<uint16_t>(ARRAY_BEGIN),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(MEASMAGN_ARRAYMAGN_),
    static_cast<uint16_t>(ARRAY_END));

CREATE_GROUP(MEASTEMP_,
    static_cast<uint16_t>(MEASTEMP_MEASUREMENT),
    static_cast<uint16_t>(MEASTEMP_TIMESTAMP));

CREATE_GROUP(TIMEDETAILED_,
    static_cast<uint16_t>(TIMEDETAILED_RELATIVETIME),
    static_cast<uint16_t>(TIMEDETAILED_UTCTIME));

CREATE_GROUP(WHITEBOARDMETRICSCOMM_,
    static_cast<uint16_t>(WHITEBOARDMETRICSCOMM_RECEIVEDBYTES),
    static_cast<uint16_t>(WHITEBOARDMETRICSCOMM_SENTBYTES));

const DescriptorItem_t s_possibleSbemItems[] = {
    {NET, "<PTH>Samples+Array.Net\n<FRM>utf8"},
    {TIME, "<PTH>Samples+Array.Time\n<FRM>int64,nillable=4294967295"},
    {WHITEBOARD_TIME, "<PTH>Samples+Array.Whiteboard.Time\n<FRM>int64,nillable=4294967295"},
    {MEASACC_TIMESTAMP, "<PTH>Samples+Array.MeasAcc.Timestamp\n<FRM>uint32"},
    {MEASECG_TIMESTAMP, "<PTH>Samples+Array.MeasECG.Timestamp\n<FRM>uint32"},
    {MEASECGMV_TIMESTAMP, "<PTH>Samples+Array.MeasECGmV.Timestamp\n<FRM>uint32"},
    {MEASGYRO_TIMESTAMP, "<PTH>Samples+Array.MeasGyro.Timestamp\n<FRM>uint32"},
    {MEASHR_AVERAGE, "<PTH>Samples+Array.MeasHR.average\n<FRM>float32"},
    {MEASIMU6_TIMESTAMP, "<PTH>Samples+Array.MeasIMU6.Timestamp\n<FRM>uint32"},
    {MEASIMU6M_TIMESTAMP, "<PTH>Samples+Array.MeasIMU6m.Timestamp\n<FRM>uint32"},
    {MEASIMU9_TIMESTAMP, "<PTH>Samples+Array.MeasIMU9.Timestamp\n<FRM>uint32"},
    {MEASMAGN_TIMESTAMP, "<PTH>Samples+Array.MeasMagn.Timestamp\n<FRM>uint32"},
    {MEASTEMP_MEASUREMENT, "<PTH>Samples+Array.MeasTemp.Measurement\n<FRM>float32"},
    {TIMEDETAILED_RELATIVETIME, "<PTH>Samples+Array.TimeDetailed.relativeTime\n<FRM>uint32"},
    {WHITEBOARDMETRICSCOMM_RECEIVEDBYTES, "<PTH>Samples+Array.WhiteboardMetricsComm.receivedBytes\n<FRM>uint32"},
    {MEASACC_ARRAYACC_X, "<PTH>Samples.Array.MeasAcc.ArrayAcc+x\n<FRM>float32"},
    {MEASACC_ARRAYACC_Y, "<PTH>Samples.Array.MeasAcc.ArrayAcc.y\n<FRM>float32"},
    {MEASACC_ARRAYACC_Z, "<PTH>Samples.Array.MeasAcc.ArrayAcc.z\n<FRM>float32"},
    {MEASECG_SAMPLES, "<PTH>Samples.MeasECG.Samples\n<FRM>int32"},
    {MEASECGMV_SAMPLES, "<PTH>Samples.MeasECGmV.Samples\n<FRM>float32"},
    {MEASGYRO_ARRAYGYRO_X, "<PTH>Samples.Array.MeasGyro.ArrayGyro+x\n<FRM>float32"},
    {MEASGYRO_ARRAYGYRO_Y, "<PTH>Samples.Array.MeasGyro.ArrayGyro.y\n<FRM>float32"},
    {MEASGYRO_ARRAYGYRO_Z, "<PTH>Samples.Array.MeasGyro.ArrayGyro.z\n<FRM>float32"},
    {MEASHR_RRDATA, "<PTH>Samples.MeasHR.rrData\n<FRM>uint16"},
    {MEASIMU6_ARRAYACC_X, "<PTH>Samples.Array.MeasIMU6.ArrayAcc+x\n<FRM>float32"},
    {MEASIMU6_ARRAYACC_Y, "<PTH>Samples.Array.MeasIMU6.ArrayAcc.y\n<FRM>float32"},
    {MEASIMU6_ARRAYACC_Z, "<PTH>Samples.Array.MeasIMU6.ArrayAcc.z\n<FRM>float32"},
    {MEASIMU6_ARRAYGYRO_X, "<PTH>Samples.Array.MeasIMU6.ArrayGyro+x\n<FRM>float32"},
    {MEASIMU6_ARRAYGYRO_Y, "<PTH>Samples.Array.MeasIMU6.ArrayGyro.y\n<FRM>float32"},
    {MEASIMU6_ARRAYGYRO_Z, "<PTH>Samples.Array.MeasIMU6.ArrayGyro.z\n<FRM>float32"},
    {MEASIMU6M_ARRAYACC_X, "<PTH>Samples.Array.MeasIMU6m.ArrayAcc+x\n<FRM>float32"},
    {MEASIMU6M_ARRAYACC_Y, "<PTH>Samples.Array.MeasIMU6m.ArrayAcc.y\n<FRM>float32"},
    {MEASIMU6M_ARRAYACC_Z, "<PTH>Samples.Array.MeasIMU6m.ArrayAcc.z\n<FRM>float32"},
    {MEASIMU6M_ARRAYMAGN_X, "<PTH>Samples.Array.MeasIMU6m.ArrayMagn+x\n<FRM>float32"},
    {MEASIMU6M_ARRAYMAGN_Y, "<PTH>Samples.Array.MeasIMU6m.ArrayMagn.y\n<FRM>float32"},
    {MEASIMU6M_ARRAYMAGN_Z, "<PTH>Samples.Array.MeasIMU6m.ArrayMagn.z\n<FRM>float32"},
    {MEASIMU9_ARRAYACC_X, "<PTH>Samples.Array.MeasIMU9.ArrayAcc+x\n<FRM>float32"},
    {MEASIMU9_ARRAYACC_Y, "<PTH>Samples.Array.MeasIMU9.ArrayAcc.y\n<FRM>float32"},
    {MEASIMU9_ARRAYACC_Z, "<PTH>Samples.Array.MeasIMU9.ArrayAcc.z\n<FRM>float32"},
    {MEASIMU9_ARRAYGYRO_X, "<PTH>Samples.Array.MeasIMU9.ArrayGyro+x\n<FRM>float32"},
    {MEASIMU9_ARRAYGYRO_Y, "<PTH>Samples.Array.MeasIMU9.ArrayGyro.y\n<FRM>float32"},
    {MEASIMU9_ARRAYGYRO_Z, "<PTH>Samples.Array.MeasIMU9.ArrayGyro.z\n<FRM>float32"},
    {MEASIMU9_ARRAYMAGN_X, "<PTH>Samples.Array.MeasIMU9.ArrayMagn+x\n<FRM>float32"},
    {MEASIMU9_ARRAYMAGN_Y, "<PTH>Samples.Array.MeasIMU9.ArrayMagn.y\n<FRM>float32"},
    {MEASIMU9_ARRAYMAGN_Z, "<PTH>Samples.Array.MeasIMU9.ArrayMagn.z\n<FRM>float32"},
    {MEASMAGN_ARRAYMAGN_X, "<PTH>Samples.Array.MeasMagn.ArrayMagn+x\n<FRM>float32"},
    {MEASMAGN_ARRAYMAGN_Y, "<PTH>Samples.Array.MeasMagn.ArrayMagn.y\n<FRM>float32"},
    {MEASMAGN_ARRAYMAGN_Z, "<PTH>Samples.Array.MeasMagn.ArrayMagn.z\n<FRM>float32"},
    {MEASTEMP_TIMESTAMP, "<PTH>Samples.Array.MeasTemp.Timestamp\n<FRM>uint32"},
    {TIMEDETAILED_UTCTIME, "<PTH>Samples.Array.TimeDetailed.utcTime\n<FRM>int64"},
    {WHITEBOARDMETRICSCOMM_SENTBYTES, "<PTH>Samples.Array.WhiteboardMetricsComm.sentBytes\n<FRM>uint32"},
    {ARRAY_BEGIN, "<PTH>["},
    {ARRAY_END, "<PTH>]"},
    {SAMPLES_ARRAY_BEGIN, "<PTH>+Samples.Array.ArrayBegin\n<FRM>uint8"},
    {ID_DESCRIPTOR_ARRAY_END_MARKER, NULL}
};

const DescriptorGroup_t s_possibleSbemGroups[] = {
    MEASACC_ARRAYACC__Group,
    MEASACC_1_Group,
    MEASACC_2_Group,
    MEASACC_4_Group,
    MEASACC_8_Group,
    MEASECG_16_Group,
    MEASECGMV_16_Group,
    MEASGYRO_ARRAYGYRO__Group,
    MEASGYRO_1_Group,
    MEASGYRO_2_Group,
    MEASGYRO_4_Group,
    MEASGYRO_8_Group,
    MEASHR_1_Group,
    MEASHR_2_Group,
    MEASHR_3_Group,
    MEASHR_4_Group,
    MEASHR_5_Group,
    MEASHR_6_Group,
    MEASHR_7_Group,
    MEASHR_8_Group,
    MEASIMU6_ARRAYACC__Group,
    MEASIMU6_ARRAYGYRO__Group,
    MEASIMU6_1_Group,
    MEASIMU6_2_Group,
    MEASIMU6_4_Group,
    MEASIMU6_8_Group,
    MEASIMU6M_ARRAYACC__Group,
    MEASIMU6M_ARRAYMAGN__Group,
    MEASIMU6M_1_Group,
    MEASIMU6M_2_Group,
    MEASIMU6M_4_Group,
    MEASIMU6M_8_Group,
    MEASIMU9_ARRAYACC__Group,
    MEASIMU9_ARRAYGYRO__Group,
    MEASIMU9_ARRAYMAGN__Group,
    MEASIMU9_1_Group,
    MEASIMU9_2_Group,
    MEASIMU9_4_Group,
    MEASIMU9_8_Group,
    MEASMAGN_ARRAYMAGN__Group,
    MEASMAGN_1_Group,
    MEASMAGN_2_Group,
    MEASMAGN_4_Group,
    MEASMAGN_8_Group,
    MEASTEMP__Group,
    TIMEDETAILED__Group,
    WHITEBOARDMETRICSCOMM__Group,
    {ID_DESCRIPTOR_ARRAY_END_MARKER, 0, NULL}
};

size_t writeToSbemBuffer_MEAS_ACC_SAMPLERATE(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.timestamp);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    for(size_t loopidx_1=0; loopidx_1<data.arrayAcc.size(); loopidx_1++)
    {
        {
            auto value = (data.arrayAcc[loopidx_1].x);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayAcc[loopidx_1].y);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayAcc[loopidx_1].z);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_MEAS_ECG_REQUIREDSAMPLERATE(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.timestamp);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    for(size_t loopidx_1=0; loopidx_1<data.samples.size(); loopidx_1++)
    {
    {
        auto value = (data.samples[loopidx_1]);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_MEAS_ECG_REQUIREDSAMPLERATE_MV(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE_MV::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.timestamp);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    for(size_t loopidx_1=0; loopidx_1<data.samples.size(); loopidx_1++)
    {
    {
        auto value = (data.samples[loopidx_1]);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_MEAS_GYRO_SAMPLERATE(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.timestamp);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    for(size_t loopidx_1=0; loopidx_1<data.arrayGyro.size(); loopidx_1++)
    {
        {
            auto value = (data.arrayGyro[loopidx_1].x);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayGyro[loopidx_1].y);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayGyro[loopidx_1].z);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_MEAS_HR(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_HR::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.average);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    for(size_t loopidx_1=0; loopidx_1<data.rrData.size(); loopidx_1++)
    {
    {
        auto value = (data.rrData[loopidx_1]);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_MEAS_IMU6_SAMPLERATE(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.timestamp);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    for(size_t loopidx_1=0; loopidx_1<data.arrayAcc.size(); loopidx_1++)
    {
        {
            auto value = (data.arrayAcc[loopidx_1].x);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayAcc[loopidx_1].y);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayAcc[loopidx_1].z);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
    }
        for(size_t loopidx_2=0; loopidx_2<data.arrayGyro.size(); loopidx_2++)
    {
            {
                auto value = (data.arrayGyro[loopidx_2].x);
                const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                    if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
            }
            {
                auto value = (data.arrayGyro[loopidx_2].y);
                const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                    if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
            }
            {
                auto value = (data.arrayGyro[loopidx_2].z);
                const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                    if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
            }
        }
    return bytesWritten;
}



size_t writeToSbemBuffer_MEAS_IMU6M_SAMPLERATE(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.timestamp);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    for(size_t loopidx_1=0; loopidx_1<data.arrayAcc.size(); loopidx_1++)
    {
        {
            auto value = (data.arrayAcc[loopidx_1].x);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayAcc[loopidx_1].y);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayAcc[loopidx_1].z);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
    }
        for(size_t loopidx_2=0; loopidx_2<data.arrayMagn.size(); loopidx_2++)
    {
            {
                auto value = (data.arrayMagn[loopidx_2].x);
                const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                    if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
            }
            {
                auto value = (data.arrayMagn[loopidx_2].y);
                const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                    if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
            }
            {
                auto value = (data.arrayMagn[loopidx_2].z);
                const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                    if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
            }
        }
    return bytesWritten;
}



size_t writeToSbemBuffer_MEAS_IMU9_SAMPLERATE(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.timestamp);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    for(size_t loopidx_1=0; loopidx_1<data.arrayAcc.size(); loopidx_1++)
    {
        {
            auto value = (data.arrayAcc[loopidx_1].x);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayAcc[loopidx_1].y);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayAcc[loopidx_1].z);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
    }
        for(size_t loopidx_2=0; loopidx_2<data.arrayGyro.size(); loopidx_2++)
    {
            {
                auto value = (data.arrayGyro[loopidx_2].x);
                const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                    if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
            }
            {
                auto value = (data.arrayGyro[loopidx_2].y);
                const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                    if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
            }
            {
                auto value = (data.arrayGyro[loopidx_2].z);
                const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                    if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
            }
        }
            for(size_t loopidx_3=0; loopidx_3<data.arrayMagn.size(); loopidx_3++)
    {
                {
                    auto value = (data.arrayMagn[loopidx_3].x);
                    const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                    for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                        if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
                }
                {
                    auto value = (data.arrayMagn[loopidx_3].y);
                    const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                    for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                        if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
                }
                {
                    auto value = (data.arrayMagn[loopidx_3].z);
                    const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
                    for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                        if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
                }
            }
    return bytesWritten;
}



size_t writeToSbemBuffer_MEAS_MAGN_SAMPLERATE(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.timestamp);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    for(size_t loopidx_1=0; loopidx_1<data.arrayMagn.size(); loopidx_1++)
    {
        {
            auto value = (data.arrayMagn[loopidx_1].x);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayMagn[loopidx_1].y);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
        {
            auto value = (data.arrayMagn[loopidx_1].z);
            const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
            for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
                if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
        }
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_MEAS_TEMP(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::MEAS_TEMP::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.measurement);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    {
        auto value = (data.timestamp);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_TIME(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::TIME::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_TIME_DETAILED(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::TIME_DETAILED::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.relativeTime);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    {
        auto value = (data.utcTime);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_WHITEBOARD_METRICS_COMM(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::WHITEBOARD_METRICS_COMM::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data.receivedBytes);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    {
        auto value = (data.sentBytes);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    return bytesWritten;
}



size_t writeToSbemBuffer_WHITEBOARD_TIME(void *buffer, size_t bufferLen, size_t startOffset, const WB_RES::LOCAL::WHITEBOARD_TIME::EVENT::NotificationType &data) {
    size_t bytesRead = 0;
    size_t bytesWritten = 0;
    uint8_t *byteBuf = static_cast<uint8_t*>(buffer);
    {
        auto value = (data);
        const uint8_t *src = reinterpret_cast<const uint8_t*>(&value);
        for(size_t i=0; i<sizeof(value); i++, src++, bytesRead++)
            if ((bytesRead >= startOffset) && (bytesWritten < bufferLen)) byteBuf[bytesWritten++] = *src;
    }
    return bytesWritten;
}



size_t getSbemLength_MEAS_ACC_SAMPLERATE(const WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::EVENT::NotificationType &data)
{
    return (0 + 4 + data.arrayAcc.size() * (0  + 4 + 4 + 4 ) );
}



size_t getSbemLength_MEAS_ECG_REQUIREDSAMPLERATE(const WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE::EVENT::NotificationType &data)
{
    return (0 + 4 + data.samples.size() * (0  + 4 ) );
}



size_t getSbemLength_MEAS_ECG_REQUIREDSAMPLERATE_MV(const WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE_MV::EVENT::NotificationType &data)
{
    return (0 + 4 + data.samples.size() * (0  + 4 ) );
}



size_t getSbemLength_MEAS_GYRO_SAMPLERATE(const WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::EVENT::NotificationType &data)
{
    return (0 + 4 + data.arrayGyro.size() * (0  + 4 + 4 + 4 ) );
}



size_t getSbemLength_MEAS_HR(const WB_RES::LOCAL::MEAS_HR::EVENT::NotificationType &data)
{
    return (0 + 4 + data.rrData.size() * (0  + 2 ) );
}



size_t getSbemLength_MEAS_IMU6_SAMPLERATE(const WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::EVENT::NotificationType &data)
{
    return (0 + 4 + data.arrayAcc.size() * (0  + 4 + 4 + 4 )  + data.arrayGyro.size() * (0  + 4 + 4 + 4 ) );
}



size_t getSbemLength_MEAS_IMU6M_SAMPLERATE(const WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::EVENT::NotificationType &data)
{
    return (0 + 4 + data.arrayAcc.size() * (0  + 4 + 4 + 4 )  + data.arrayMagn.size() * (0  + 4 + 4 + 4 ) );
}



size_t getSbemLength_MEAS_IMU9_SAMPLERATE(const WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::EVENT::NotificationType &data)
{
    return (0 + 4 + data.arrayAcc.size() * (0  + 4 + 4 + 4 )  + data.arrayGyro.size() * (0  + 4 + 4 + 4 )  + data.arrayMagn.size() * (0  + 4 + 4 + 4 ) );
}



size_t getSbemLength_MEAS_MAGN_SAMPLERATE(const WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::EVENT::NotificationType &data)
{
    return (0 + 4 + data.arrayMagn.size() * (0  + 4 + 4 + 4 ) );
}



size_t getSbemLength_MEAS_TEMP(const WB_RES::LOCAL::MEAS_TEMP::EVENT::NotificationType &data)
{
    return (0 + 4 + 4);
}



size_t getSbemLength_TIME(const WB_RES::LOCAL::TIME::EVENT::NotificationType &data)
{
    return (0 + 8);
}



size_t getSbemLength_TIME_DETAILED(const WB_RES::LOCAL::TIME_DETAILED::EVENT::NotificationType &data)
{
    return (0 + 4 + 8);
}



size_t getSbemLength_WHITEBOARD_METRICS_COMM(const WB_RES::LOCAL::WHITEBOARD_METRICS_COMM::EVENT::NotificationType &data)
{
    return (0 + 4 + 4);
}



size_t getSbemLength_WHITEBOARD_TIME(const WB_RES::LOCAL::WHITEBOARD_TIME::EVENT::NotificationType &data)
{
    return (0 + 8);
}



int16_t getSbemLengthConst(whiteboard::LocalResourceId localResId)
{
    switch(localResId)
    {
    case WB_RES::LOCAL::MEAS_TEMP::LID:
        return (8);
    case WB_RES::LOCAL::TIME::LID:
        return (8);
    case WB_RES::LOCAL::TIME_DETAILED::LID:
        return (12);
    case WB_RES::LOCAL::WHITEBOARD_METRICS_COMM::LID:
        return (8);
    case WB_RES::LOCAL::WHITEBOARD_TIME::LID:
        return (8);
    default:
        return -1;
    }
}


size_t getSbemLength(whiteboard::LocalResourceId localResId, const whiteboard::Value &data)
{
    switch(localResId)
    {
    case WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::LID:
        return getSbemLength_MEAS_ACC_SAMPLERATE(data.convertTo<WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE::LID:
        return getSbemLength_MEAS_ECG_REQUIREDSAMPLERATE(data.convertTo<WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE_MV::LID:
        return getSbemLength_MEAS_ECG_REQUIREDSAMPLERATE_MV(data.convertTo<WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE_MV::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::LID:
        return getSbemLength_MEAS_GYRO_SAMPLERATE(data.convertTo<WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_HR::LID:
        return getSbemLength_MEAS_HR(data.convertTo<WB_RES::LOCAL::MEAS_HR::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::LID:
        return getSbemLength_MEAS_IMU6_SAMPLERATE(data.convertTo<WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::LID:
        return getSbemLength_MEAS_IMU6M_SAMPLERATE(data.convertTo<WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::LID:
        return getSbemLength_MEAS_IMU9_SAMPLERATE(data.convertTo<WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::LID:
        return getSbemLength_MEAS_MAGN_SAMPLERATE(data.convertTo<WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_TEMP::LID:
        return getSbemLength_MEAS_TEMP(data.convertTo<WB_RES::LOCAL::MEAS_TEMP::EVENT::NotificationType>());
    case WB_RES::LOCAL::TIME::LID:
        return getSbemLength_TIME(data.convertTo<WB_RES::LOCAL::TIME::EVENT::NotificationType>());
    case WB_RES::LOCAL::TIME_DETAILED::LID:
        return getSbemLength_TIME_DETAILED(data.convertTo<WB_RES::LOCAL::TIME_DETAILED::EVENT::NotificationType>());
    case WB_RES::LOCAL::WHITEBOARD_METRICS_COMM::LID:
        return getSbemLength_WHITEBOARD_METRICS_COMM(data.convertTo<WB_RES::LOCAL::WHITEBOARD_METRICS_COMM::EVENT::NotificationType>());
    case WB_RES::LOCAL::WHITEBOARD_TIME::LID:
        return getSbemLength_WHITEBOARD_TIME(data.convertTo<WB_RES::LOCAL::WHITEBOARD_TIME::EVENT::NotificationType>());
    }
    DEBUGLOG("getSbemLength error: Unknown localResourceId: %u", localResId);
    return 0;
}


size_t writeToSbemBuffer(void *buffer, size_t bufferLen, size_t startOffset, whiteboard::LocalResourceId localResId, const whiteboard::Value &data)
{
    switch(localResId)
    {
    case WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::LID:
        return writeToSbemBuffer_MEAS_ACC_SAMPLERATE(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE::LID:
        return writeToSbemBuffer_MEAS_ECG_REQUIREDSAMPLERATE(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE_MV::LID:
        return writeToSbemBuffer_MEAS_ECG_REQUIREDSAMPLERATE_MV(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE_MV::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::LID:
        return writeToSbemBuffer_MEAS_GYRO_SAMPLERATE(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_HR::LID:
        return writeToSbemBuffer_MEAS_HR(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_HR::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::LID:
        return writeToSbemBuffer_MEAS_IMU6_SAMPLERATE(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::LID:
        return writeToSbemBuffer_MEAS_IMU6M_SAMPLERATE(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::LID:
        return writeToSbemBuffer_MEAS_IMU9_SAMPLERATE(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::LID:
        return writeToSbemBuffer_MEAS_MAGN_SAMPLERATE(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::EVENT::NotificationType>());
    case WB_RES::LOCAL::MEAS_TEMP::LID:
        return writeToSbemBuffer_MEAS_TEMP(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::MEAS_TEMP::EVENT::NotificationType>());
    case WB_RES::LOCAL::TIME::LID:
        return writeToSbemBuffer_TIME(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::TIME::EVENT::NotificationType>());
    case WB_RES::LOCAL::TIME_DETAILED::LID:
        return writeToSbemBuffer_TIME_DETAILED(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::TIME_DETAILED::EVENT::NotificationType>());
    case WB_RES::LOCAL::WHITEBOARD_METRICS_COMM::LID:
        return writeToSbemBuffer_WHITEBOARD_METRICS_COMM(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::WHITEBOARD_METRICS_COMM::EVENT::NotificationType>());
    case WB_RES::LOCAL::WHITEBOARD_TIME::LID:
        return writeToSbemBuffer_WHITEBOARD_TIME(buffer, bufferLen, startOffset, data.convertTo<WB_RES::LOCAL::WHITEBOARD_TIME::EVENT::NotificationType>());
    }
    DEBUGLOG("writeToSbemBuffer error: Unknown localResourceId: %u", localResId);
    return 0;
}


const SbemResID2ItemIdMapping s_sbemResID2ItemIdMap[] = {
    {WB_RES::LOCAL::TIME::LID, &s_possibleSbemItems[1] },
    {WB_RES::LOCAL::WHITEBOARD_TIME::LID, &s_possibleSbemItems[2] },
    ITEM_MAPPING_END_MARKER
};

const SbemResID2GrpIdMapping s_sbemResID2GrpIdMap[] = {
    { WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::LID,  + 4 +  (1)  * (0  + 4 + 4 + 4 ) , &MEASACC_1_Group },
    { WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::LID,  + 4 +  (2)  * (0  + 4 + 4 + 4 ) , &MEASACC_2_Group },
    { WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::LID,  + 4 +  (4)  * (0  + 4 + 4 + 4 ) , &MEASACC_4_Group },
    { WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::LID,  + 4 +  (8)  * (0  + 4 + 4 + 4 ) , &MEASACC_8_Group },
    { WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE::LID,  + 4 +  (16)  * (0  + 4 ) , &MEASECG_16_Group },
    { WB_RES::LOCAL::MEAS_ECG_REQUIREDSAMPLERATE_MV::LID,  + 4 +  (16)  * (0  + 4 ) , &MEASECGMV_16_Group },
    { WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::LID,  + 4 +  (1)  * (0  + 4 + 4 + 4 ) , &MEASGYRO_1_Group },
    { WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::LID,  + 4 +  (2)  * (0  + 4 + 4 + 4 ) , &MEASGYRO_2_Group },
    { WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::LID,  + 4 +  (4)  * (0  + 4 + 4 + 4 ) , &MEASGYRO_4_Group },
    { WB_RES::LOCAL::MEAS_GYRO_SAMPLERATE::LID,  + 4 +  (8)  * (0  + 4 + 4 + 4 ) , &MEASGYRO_8_Group },
    { WB_RES::LOCAL::MEAS_HR::LID,  + 4 +  (1)  * (0  + 2 ) , &MEASHR_1_Group },
    { WB_RES::LOCAL::MEAS_HR::LID,  + 4 +  (2)  * (0  + 2 ) , &MEASHR_2_Group },
    { WB_RES::LOCAL::MEAS_HR::LID,  + 4 +  (3)  * (0  + 2 ) , &MEASHR_3_Group },
    { WB_RES::LOCAL::MEAS_HR::LID,  + 4 +  (4)  * (0  + 2 ) , &MEASHR_4_Group },
    { WB_RES::LOCAL::MEAS_HR::LID,  + 4 +  (5)  * (0  + 2 ) , &MEASHR_5_Group },
    { WB_RES::LOCAL::MEAS_HR::LID,  + 4 +  (6)  * (0  + 2 ) , &MEASHR_6_Group },
    { WB_RES::LOCAL::MEAS_HR::LID,  + 4 +  (7)  * (0  + 2 ) , &MEASHR_7_Group },
    { WB_RES::LOCAL::MEAS_HR::LID,  + 4 +  (8)  * (0  + 2 ) , &MEASHR_8_Group },
    { WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::LID,  + 4 +  (1)  * (0  + 4 + 4 + 4 )  +  (1)  * (0  + 4 + 4 + 4 ) , &MEASIMU6_1_Group },
    { WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::LID,  + 4 +  (2)  * (0  + 4 + 4 + 4 )  +  (2)  * (0  + 4 + 4 + 4 ) , &MEASIMU6_2_Group },
    { WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::LID,  + 4 +  (4)  * (0  + 4 + 4 + 4 )  +  (4)  * (0  + 4 + 4 + 4 ) , &MEASIMU6_4_Group },
    { WB_RES::LOCAL::MEAS_IMU6_SAMPLERATE::LID,  + 4 +  (8)  * (0  + 4 + 4 + 4 )  +  (8)  * (0  + 4 + 4 + 4 ) , &MEASIMU6_8_Group },
    { WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::LID,  + 4 +  (1)  * (0  + 4 + 4 + 4 )  +  (1)  * (0  + 4 + 4 + 4 ) , &MEASIMU6M_1_Group },
    { WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::LID,  + 4 +  (2)  * (0  + 4 + 4 + 4 )  +  (2)  * (0  + 4 + 4 + 4 ) , &MEASIMU6M_2_Group },
    { WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::LID,  + 4 +  (4)  * (0  + 4 + 4 + 4 )  +  (4)  * (0  + 4 + 4 + 4 ) , &MEASIMU6M_4_Group },
    { WB_RES::LOCAL::MEAS_IMU6M_SAMPLERATE::LID,  + 4 +  (8)  * (0  + 4 + 4 + 4 )  +  (8)  * (0  + 4 + 4 + 4 ) , &MEASIMU6M_8_Group },
    { WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::LID,  + 4 +  (1)  * (0  + 4 + 4 + 4 )  +  (1)  * (0  + 4 + 4 + 4 )  +  (1)  * (0  + 4 + 4 + 4 ) , &MEASIMU9_1_Group },
    { WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::LID,  + 4 +  (2)  * (0  + 4 + 4 + 4 )  +  (2)  * (0  + 4 + 4 + 4 )  +  (2)  * (0  + 4 + 4 + 4 ) , &MEASIMU9_2_Group },
    { WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::LID,  + 4 +  (4)  * (0  + 4 + 4 + 4 )  +  (4)  * (0  + 4 + 4 + 4 )  +  (4)  * (0  + 4 + 4 + 4 ) , &MEASIMU9_4_Group },
    { WB_RES::LOCAL::MEAS_IMU9_SAMPLERATE::LID,  + 4 +  (8)  * (0  + 4 + 4 + 4 )  +  (8)  * (0  + 4 + 4 + 4 )  +  (8)  * (0  + 4 + 4 + 4 ) , &MEASIMU9_8_Group },
    { WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::LID,  + 4 +  (1)  * (0  + 4 + 4 + 4 ) , &MEASMAGN_1_Group },
    { WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::LID,  + 4 +  (2)  * (0  + 4 + 4 + 4 ) , &MEASMAGN_2_Group },
    { WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::LID,  + 4 +  (4)  * (0  + 4 + 4 + 4 ) , &MEASMAGN_4_Group },
    { WB_RES::LOCAL::MEAS_MAGN_SAMPLERATE::LID,  + 4 +  (8)  * (0  + 4 + 4 + 4 ) , &MEASMAGN_8_Group },
    { WB_RES::LOCAL::MEAS_TEMP::LID,  + 4 + 4, &MEASTEMP__Group },
    { WB_RES::LOCAL::TIME_DETAILED::LID,  + 4 + 8, &TIMEDETAILED__Group },
    { WB_RES::LOCAL::WHITEBOARD_METRICS_COMM::LID,  + 4 + 4, &WHITEBOARDMETRICSCOMM__Group },
    GROUP_MAPPING_END_MARKER
};

uint16_t getSbemItemsCount()
{
    return SbemValueIds_COUNT;
}

uint16_t getSbemGroupsCount()
{
    return SbemAllIds_COUNT - SbemValueIds_COUNT;
}

uint16_t getFirstSbemGroupId()
{
    return BEFORE_GROUPS_ID + 1;
}
