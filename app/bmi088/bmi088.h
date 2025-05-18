#ifndef BMI088_BMI088_H
#define BMI088_BMI088_H

#include "bmi088_config.h"
#include "bmi088_registers.h"
#include "bmi088_utility.h"

typedef struct {
    bmi088_config_t config;
    bmi088_interface_t interface;
} bmi088_t;

bmi088_err_t bmi088_initialize(bmi088_t* bmi088, bmi088_config_t const* config, bmi088_interface_t const* interface);
bmi088_err_t bmi088_deinitialize(bmi088_t* bmi088);

bmi088_err_t bmi088_get_acc_data_raw(bmi088_t const* bmi088, bmi088_data_raw_t* raw);
bmi088_err_t bmi088_get_acc_data_scaled(bmi088_t const* bmi088, bmi088_data_scaled_t* scaled);

bmi088_err_t bmi088_get_gyro_data_raw(bmi088_t const* bmi088, bmi088_data_raw_t* raw);
bmi088_err_t bmi088_get_gyro_data_scaled(bmi088_t const* bmi088, bmi088_data_scaled_t* scaled);

bmi088_err_t bmi088_get_temp_data_raw(bmi088_t const* bmi088, int16_t* raw);
bmi088_err_t bmi088_get_temp_data_scaled(bmi088_t const* bmi088, float32_t* scaled);

bmi088_err_t bmi088_set_acc_softreset_reg(bmi088_t const* bmi088, bmi088_acc_softreset_t reg);

bmi088_err_t bmi088_set_acc_pwr_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_pwr_ctrl_t reg);
bmi088_err_t bmi088_get_acc_pwr_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_pwr_ctrl_t* reg);

bmi088_err_t bmi088_set_acc_pwr_conf_reg(bmi088_t const* bmi088, bmi088_acc_pwr_conf_t reg);
bmi088_err_t bmi088_get_acc_pwr_conf_reg(bmi088_t const* bmi088, bmi088_acc_pwr_conf_t* reg);

bmi088_err_t bmi088_set_acc_self_test_reg(bmi088_t const* bmi088, bmi088_acc_self_test_t reg);
bmi088_err_t bmi088_get_acc_self_test_reg(bmi088_t const* bmi088, bmi088_acc_self_test_t* reg);

bmi088_err_t bmi088_set_acc_int_map_data_reg(bmi088_t const* bmi088, bmi088_acc_int_map_data_t reg);
bmi088_err_t bmi088_get_acc_int_map_data_reg(bmi088_t const* bmi088, bmi088_acc_int_map_data_t* reg);

bmi088_err_t bmi088_set_acc_int2_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int2_io_ctrl_t reg);
bmi088_err_t bmi088_get_acc_int2_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int2_io_ctrl_t* reg);

bmi088_err_t bmi088_set_acc_int1_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int1_io_ctrl_t reg);
bmi088_err_t bmi088_get_acc_int1_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int1_io_ctrl_t* reg);

bmi088_err_t bmi088_set_acc_fifo_config_1_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_1_t reg);
bmi088_err_t bmi088_get_acc_fifo_config_1_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_1_t* reg);

bmi088_err_t bmi088_set_acc_fifo_config_0_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_0_t reg);
bmi088_err_t bmi088_get_acc_fifo_config_0_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_0_t* reg);

bmi088_err_t bmi088_set_acc_fifo_wtm_reg(bmi088_t const* bmi088, bmi088_acc_fifo_wtm_t reg);

bmi088_err_t bmi088_set_acc_fifo_downs_reg(bmi088_t const* bmi088, bmi088_acc_fifo_downs_t reg);
bmi088_err_t bmi088_get_acc_fifo_downs_reg(bmi088_t const* bmi088, bmi088_acc_fifo_downs_t* reg);

bmi088_err_t bmi088_set_acc_range_reg(bmi088_t const* bmi088, bmi088_acc_range_t reg);
bmi088_err_t bmi088_get_acc_range_reg(bmi088_t const* bmi088, bmi088_acc_range_t* reg);

bmi088_err_t bmi088_get_acc_conf_reg(bmi088_t const* bmi088, bmi088_acc_conf_t* reg);
bmi088_err_t bmi088_set_acc_conf_reg(bmi088_t const* bmi088, bmi088_acc_conf_t reg);

bmi088_err_t bmi088_get_acc_fifo_data_reg(bmi088_t const* bmi088, bmi088_acc_fifo_data_t* reg);

bmi088_err_t bmi088_get_acc_fifo_length_1_reg(bmi088_t const* bmi088, bmi088_acc_fifo_length_1_t* reg);
bmi088_err_t bmi088_get_acc_fifo_length_0_reg(bmi088_t const* bmi088, bmi088_acc_fifo_length_0_t* reg);

bmi088_err_t bmi088_get_acc_temp_lsb_reg(bmi088_t const* bmi088, bmi088_acc_temp_lsb_t* reg);
bmi088_err_t bmi088_get_acc_temp_msb_reg(bmi088_t const* bmi088, bmi088_acc_temp_lsb_t* reg);

bmi088_err_t bmi088_get_acc_int_stat_reg(bmi088_t const* bmi088, bmi088_acc_int_stat_t* reg);

bmi088_err_t bmi088_get_acc_sensortime_2_reg(bmi088_t const* bmi088, bmi088_acc_sensortime_2_t* reg);
bmi088_err_t bmi088_get_acc_sensortime_1_reg(bmi088_t const* bmi088, bmi088_acc_sensortime_1_t* reg);
bmi088_err_t bmi088_get_acc_sensortime_0_reg(bmi088_t const* bmi088, bmi088_acc_sensortime_0_t* reg);

bmi088_err_t bmi088_get_acc_z_msb_reg(bmi088_t const* bmi088, bmi088_acc_z_msb_t* reg);
bmi088_err_t bmi088_get_acc_z_lsb_reg(bmi088_t const* bmi088, bmi088_acc_z_lsb_t* reg);

bmi088_err_t bmi088_get_acc_y_msb_reg(bmi088_t const* bmi088, bmi088_acc_y_msb_t* reg);
bmi088_err_t bmi088_get_acc_y_lsb_reg(bmi088_t const* bmi088, bmi088_acc_y_lsb_t* reg);

bmi088_err_t bmi088_get_acc_x_msb_reg(bmi088_t const* bmi088, bmi088_acc_x_msb_t* reg);
bmi088_err_t bmi088_get_acc_x_lsb_reg(bmi088_t const* bmi088, bmi088_acc_x_lsb_t* reg);

bmi088_err_t bmi088_get_acc_status_reg(bmi088_t const* bmi088, bmi088_acc_status_t* reg);

bmi088_err_t bmi088_get_acc_err_reg(bmi088_t const* bmi088, bmi088_acc_err_t* reg);

bmi088_err_t bmi088_get_acc_chip_id_reg(bmi088_t const* bmi088, bmi088_acc_chip_id_t* reg);

bmi088_err_t bmi088_get_gyro_fifo_data_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_data_t* reg);

bmi088_err_t bmi088_set_gyro_fifo_config_1_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_1_t reg);
bmi088_err_t bmi088_get_gyro_fifo_config_1_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_1_t* reg);

bmi088_err_t bmi088_set_gyro_fifo_config_0_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_0_t reg);
bmi088_err_t bmi088_get_gyro_fifo_config_0_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_0_t* reg);

bmi088_err_t bmi088_set_gyro_self_test_reg(bmi088_t const* bmi088, bmi088_gyro_self_test_t reg);
bmi088_err_t bmi088_get_gyro_self_test_reg(bmi088_t const* bmi088, bmi088_gyro_self_test_t* reg);

bmi088_err_t bmi088_set_gyro_fifo_ext_int_s_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_ext_int_s_t reg);
bmi088_err_t bmi088_get_gyro_fifo_ext_int_s_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_ext_int_s_t* reg);

bmi088_err_t bmi088_set_gyro_fifo_wtm_en_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_wm_en_t reg);
bmi088_err_t bmi088_get_gyro_fifo_wtm_en_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_wm_en_t* reg);

bmi088_err_t bmi088_set_gyro_int3_int4_io_map_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_map_t reg);
bmi088_err_t bmi088_get_gyro_int3_int4_io_map_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_map_t* reg);

bmi088_err_t bmi088_set_gyro_int3_int4_io_conf_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_conf_t reg);
bmi088_err_t bmi088_get_gyro_int3_int4_io_conf_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_conf_t* reg);

bmi088_err_t bmi088_set_gyro_int_ctrl_reg(bmi088_t const* bmi088, bmi088_gyro_int_ctrl_t reg);
bmi088_err_t bmi088_get_gyro_int_ctrl_reg(bmi088_t const* bmi088, bmi088_gyro_int_ctrl_t* reg);

bmi088_err_t bmi088_set_gyro_softreset_reg(bmi088_t const* bmi088, bmi088_gyro_softreset_t* reg);

bmi088_err_t bmi088_set_gyro_lmp1_reg(bmi088_t const* bmi088, bmi088_gyro_lmp1_t reg);
bmi088_err_t bmi088_get_gyro_lmp1_reg(bmi088_t const* bmi088, bmi088_gyro_lmp1_t* reg);

bmi088_err_t bmi088_set_gyro_bandwidth_reg(bmi088_t const* bmi088, bmi088_gyro_bandwidth_t reg);
bmi088_err_t bmi088_get_gyro_bandwidth_reg(bmi088_t const* bmi088, bmi088_gyro_bandwidth_t* reg);

bmi088_err_t bmi088_set_gyro_range_reg(bmi088_t const* bmi088, bmi088_gyro_range_t reg);
bmi088_err_t bmi088_get_gyro_range_reg(bmi088_t const* bmi088, bmi088_gyro_range_t* reg);

bmi088_err_t bmi088_get_gyro_fifo_status_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_status_t* reg);

bmi088_err_t bmi088_get_get_gyro_int_stat_reg(bmi088_t const* bmi088, bmi088_gyro_int_stat_t* reg);

bmi088_err_t bmi088_get_gyro_rate_z_msb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_z_msb_t* reg);
bmi088_err_t bmi088_get_gyro_rate_z_lsb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_z_lsb_t* reg);

bmi088_err_t bmi088_get_gyro_rate_y_msb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_y_msb_t* reg);
bmi088_err_t bmi088_get_gyro_rate_y_lsb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_y_lsb_t* reg);

bmi088_err_t bmi088_get_gyro_rate_x_msb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_x_msb_t* reg);
bmi088_err_t bmi088_get_gyro_rate_x_lsb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_x_lsb_t* reg);

bmi088_err_t bmi088_gyro_chip_id_reg(bmi088_t const* bmi088, bmi088_gyro_chip_id_t* reg);

#endif // BMI088_BMI088_H