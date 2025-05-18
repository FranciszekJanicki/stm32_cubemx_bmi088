#ifndef BMI088_BMI088_REGISTERS_H
#define BMI088_BMI088_REGISTERS_H

#include <stdint.h>

#define PACKED __attribute__((packed))

typedef struct {
    uint8_t softreset : 8;
} PACKED bmi088_acc_softreset_t;

typedef struct {
    uint8_t acc_enable : 8;
} PACKED bmi088_acc_pwr_ctrl_t;

typedef struct {
    uint8_t pwr_save_mode : 8;
} PACKED bmi088_acc_pwr_conf_t;

typedef struct {
    uint8_t acc_self_test : 8;
} PACKED bmi088_acc_self_test_t;

typedef struct {
    uint8_t : 1;
    uint8_t int2_drdy : 1;
    uint8_t int2_fwm : 1;
    uint8_t int2_ffull : 1;
    uint8_t : 1;
    uint8_t int1_drdy : 1;
    uint8_t int1_fwm : 1;
    uint8_t int1_ffull : 1;
} PACKED bmi088_acc_int_map_data_t;

typedef struct {
    uint8_t : 3;
    uint8_t int2_in : 1;
    uint8_t int2_out : 1;
    uint8_t int2_od : 1;
    uint8_t int2_lvl : 1;
    uint8_t : 1;
} PACKED bmi088_acc_int2_io_ctrl_t;

typedef struct {
    uint8_t : 3;
    uint8_t int1_in : 1;
    uint8_t int1_out : 1;
    uint8_t int1_od : 1;
    uint8_t int1_lvl : 1;
    uint8_t : 1;
} PACKED bmi088_acc_int1_io_ctrl_t;

typedef struct {
    uint8_t : 1;
    uint8_t acc_en : 1;
    uint8_t : 2;
    uint8_t int1_en : 1;
    uint8_t int2_en : 1;
    uint8_t : 2;
} PACKED bmi088_acc_fifo_config_1_t;

typedef struct {
    uint8_t : 7;
    uint8_t mode : 1;
} PACKED bmi088_acc_fifo_config_0_t;

typedef struct {
    uint8_t : 2;
    uint16_t fifo_water_mark : 14;
} PACKED bmi088_acc_fifo_wtm_t;

typedef struct {
    uint8_t : 1;
    uint8_t fifo_downs : 2;
    uint8_t : 5;
} PACKED bmi088_acc_fifo_downs_t;

typedef struct {
    uint8_t : 6;
    uint8_t acc_range : 2;
} PACKED bmi088_acc_range_t;

typedef struct {
    uint8_t acc_bwp : 4;
    uint8_t acc_odr : 4;
} PACKED bmi088_acc_conf_t;

typedef struct {
    uint8_t fifo_data : 8;
} PACKED bmi088_acc_fifo_data_t;

typedef struct {
    uint8_t : 2;
    uint8_t fifo_byte_counter_13to8 : 6;
} PACKED bmi088_acc_fifo_length_1_t;

typedef struct {
    uint8_t fifo_byte_counter_7to0 : 8;
} PACKED bmi088_acc_fifo_length_0_t;

typedef struct {
    uint8_t temperature_2to0 : 3;
    uint8_t : 5;
} PACKED bmi088_acc_temp_lsb_t;

typedef struct {
    uint8_t temperature_10to3 : 8;
} PACKED bmi088_acc_temp_msb_t;

typedef struct {
    uint8_t acc_drdy : 1;
    uint8_t : 7;
} PACKED bmi088_acc_int_stat_t;

typedef struct {
    uint8_t sensor_time_23to16 : 8;
} PACKED bmi088_acc_sensortime_2_t;

typedef struct {
    uint8_t sensor_time_15to8 : 8;
} PACKED bmi088_acc_sensortime_1_t;

typedef struct {
    uint8_t sensor_time_7to0 : 8;
} PACKED bmi088_acc_sensortime_0_t;

typedef struct {
    uint8_t acc_z_15to8 : 8;
} PACKED bmi088_acc_z_msb_t;

typedef struct {
    uint8_t acc_z_7to0 : 8;
} PACKED bmi088_acc_z_lsb_t;

typedef struct {
    uint8_t acc_y_15to8 : 8;
} PACKED bmi088_acc_y_msb_t;

typedef struct {
    uint8_t acc_y_7to0 : 8;
} PACKED bmi088_acc_y_lsb_t;

typedef struct {
    uint8_t acc_x_15to8 : 8;
} PACKED bmi088_acc_x_msb_t;

typedef struct {
    uint8_t acc_x_7to0 : 8;
} PACKED bmi088_acc_x_lsb_t;

typedef struct {
    uint8_t drdy_acc : 1;
    uint8_t : 7;
} PACKED bmi088_acc_status_t;

typedef struct {
    uint8_t : 3;
    uint8_t error_code : 3;
    uint8_t : 1;
    uint8_t fatal_err : 1;
} PACKED bmi088_acc_err_t;

typedef struct {
    uint8_t acc_chip_id : 8;
} PACKED bmi088_acc_chip_id_t;

typedef struct {
    uint8_t fifo_data_output : 8;
} PACKED bmi088_gyro_fifo_data_t;

typedef struct {
    uint8_t fifo_mode : 1;
    uint8_t : 7;
} PACKED bmi088_gyro_fifo_config_1_t;

typedef struct {
    uint8_t fifo_wm_lvl_trig_retain : 8;
} PACKED bmi088_gyro_fifo_config_0_t;

typedef struct {
    uint8_t : 3;
    uint8_t rate_ok : 1;
    uint8_t : 1;
    uint8_t bist_fail : 1;
    uint8_t bist_rdy : 1;
    uint8_t trig_bist : 1;
} PACKED bmi088_gyro_self_test_t;

typedef struct {
    uint8_t : 2;
    uint8_t ext_fifo_s_en : 1;
    uint8_t ext_fifo_s_sel : 1;
    uint8_t : 4;
} PACKED bmi088_gyro_fifo_ext_int_s_t;

typedef struct {
    uint8_t fifo_wm_en : 8;
} PACKED bmi088_gyro_fifo_wm_en_t;

typedef struct {
    uint8_t int4_data : 1;
    uint8_t : 1;
    uint8_t int4_fifo : 1;
    uint8_t : 2;
    uint8_t int3_fifo : 1;
    uint8_t : 1;
    uint8_t int3_data : 1;
} PACKED bmi088_gyro_int3_int4_io_map_t;

typedef struct {
    uint8_t : 4;
    uint8_t int4_od : 1;
    uint8_t int4_lvl : 1;
    uint8_t int3_od : 1;
    uint8_t int3_lvl : 1;
} PACKED bmi088_gyro_int3_int4_io_conf_t;

typedef struct {
    uint8_t data_en : 1;
    uint8_t fifo_en : 1;
    uint8_t : 6;
} PACKED bmi088_gyro_int_ctrl_t;

typedef struct {
    uint8_t softreset : 8;
} PACKED bmi088_gyro_softreset_t;

typedef struct {
    uint8_t gyro_pm : 8;
} PACKED bmi088_gyro_lmp1_t;

typedef struct {
    uint8_t gyro_bw : 8;
} PACKED bmi088_gyro_bandwidth_t;

typedef struct {
    uint8_t gyro_range : 8;
} PACKED bmi088_gyro_range_t;

typedef struct {
    uint8_t fifo_overrun : 1;
    uint8_t fifo_frame_counter : 7;
} PACKED bmi088_gyro_fifo_status_t;

typedef struct {
    uint8_t gyro_drdy : 1;
    uint8_t : 2;
    uint8_t fifo_int : 1;
    uint8_t : 4;
} PACKED bmi088_gyro_int_stat_t;

typedef struct {
    uint8_t rate_z_15to8 : 8;
} PACKED bmi088_gyro_rate_z_msb_t;

typedef struct {
    uint8_t rate_z_7to0 : 8;
} PACKED bmi088_gyro_rate_z_lsb_t;

typedef struct {
    uint8_t rate_y_15to8 : 8;
} PACKED bmi088_gyro_rate_y_msb_t;

typedef struct {
    uint8_t rate_y_7to0 : 8;
} PACKED bmi088_gyro_rate_y_lsb_t;

typedef struct {
    uint8_t rate_x_15to8 : 8;
} PACKED bmi088_gyro_rate_x_msb_t;

typedef struct {
    uint8_t rate_x_7to0 : 8;
} PACKED bmi088_gyro_rate_x_lsb_t;

typedef struct {
    uint8_t gyro_chip_id : 8;
} PACKED bmi088_gyro_chip_id_t;

#undef PACKED

#endif // BMI088_BMI088_REGISTERS_H
