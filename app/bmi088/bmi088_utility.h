#ifndef BMI088_BMI088_UTILITY_H
#define BMI088_BMI088_UTILITY_H

#include "bmi088_registers.h"
#include <assert.h>
#include <stdint.h>

inline uint8_t bmi088_acc_softreset_encode(bmi088_acc_softreset_t value)
{
    return (value.softreset & 0xFF);
}

inline bmi088_acc_softreset_t bmi088_acc_softreset_decode(uint8_t reg_value)
{
    return (bmi088_acc_softreset_t){.softreset = (reg_value & 0xFF)};
}

inline uint8_t bmi088_acc_pwr_conf_encode(bmi088_acc_pwr_conf_t value)
{
    return (value.pwr_save_mode & 0xFF);
}

inline bmi088_acc_pwr_conf_t bmi088_acc_pwr_conf_decode(uint8_t reg_value)
{
    return (bmi088_acc_pwr_conf_t){.pwr_save_mode = (reg_value & 0xFF)};
}

inline uint8_t bmi088_acc_self_test_encode(bmi088_acc_self_test_t value)
{
    return (value.acc_self_test & 0xFF);
}

inline bmi088_acc_self_test_t bmi088_acc_selt_test_decode(uint8_t reg_value)
{
    return (bmi088_acc_self_test_t){.acc_self_test = (reg_value & 0xFF)};
}

inline uint8_t bmi088_acc_int_map_data_encode(bmi088_acc_int_map_data_t value)
{
    return ((value.int2_drdy & 0x01) << 6) | ((value.int2_fwm & 0x01) << 5) | ((value.int2_ffull & 0x01) << 4) |
           ((value.int1_drdy & 0x01) << 2) | ((value.int1_fwm & 0x01) << 1) | (value.int1_ffull & 0x01);
}

inline bmi088_acc_int_map_data_t bmi088_acc_int_map_data_decode(uint8_t reg_value)
{
    return (bmi088_acc_int_map_data_t){.int2_drdy = ((reg_value >> 6) & 0x01),
                                       .int2_fwm = ((reg_value >> 5) & 0x01),
                                       .int2_ffull = ((reg_value >> 4) & 0x01),
                                       .int1_drdy = ((reg_value >> 2) & 0x01),
                                       .int1_fwm = ((reg_value >> 1) & 0x01),
                                       .int1_ffull = (reg_value & 0x01)};
}

inline uint8_t bmi088_acc_int2_io_ctrl_encode(bmi088_acc_int2_io_ctrl_t value)
{
    return ((value.int2_in & 0x01) << 4) | ((value.int2_out & 0x01) << 3) | ((value.int2_od & 0x01) << 2) |
           ((value.int2_lvl & 0x01) << 1);
}

inline bmi088_acc_int2_io_ctrl_t bmi088_acc_int2_io_ctrl_decode(uint8_t reg_value)
{
    return (bmi088_acc_int2_io_ctrl_t){.int2_in = ((reg_value >> 4) & 0x01),
                                       .int2_out = ((reg_value >> 3) & 0x01),
                                       .int2_od = ((reg_value >> 2) & 0x01),
                                       .int2_lvl = ((reg_value >> 1) & 0x01)};
}

inline uint8_t bmi088_acc_int1_io_ctrl_encode(bmi088_acc_int1_io_ctrl_t value)
{
    return (uint8_t){0};
}

inline bmi088_acc_int1_io_ctrl_t bmi088_acc_int1_io_ctrl_decode(uint8_t reg_value)
{
    return (bmi088_acc_int1_io_ctrl_t){};
}

inline uint8_t bmi088_acc_fifo_config_encode(bmi088_acc_fifo_config_t value)
{
    return 0;
}

inline bmi088_acc_fifo_config_t bmi088_acc_fifo_config_decode(uint8_t reg_value)
{
    return (bmi088_acc_fifo_config_t){};
}

inline uint16_t bmi088_acc_fifo_wtm_encode(bmi088_acc_fifo_wtm_t value)
{
    return 0;
}

inline bmi088_acc_fifo_wtm_t bmi088_acc_fifo_wtm_decode(uint16_t reg_value)
{
    return (bmi088_acc_fifo_wtm_t){};
}

inline uint8_t bmi088_acc_fifo_downs_encode(bmi088_acc_fifo_downs_t value)
{
    return 0;
}

inline bmi088_acc_fifo_downs_t bmi088_acc_fifo_downs_decode(uint8_t reg_value)
{
    return (bmi088_acc_fifo_downs_t){};
}

inline uint8_t bmi088_acc_range_encode(bmi088_acc_range_t value)
{
    return 0;
}

inline bmi088_acc_range_t bmi088_acc_range_decode(uint8_t reg_value)
{
    return (bmi088_acc_range_t){};
}

inline uint8_t bmi088_acc_conf_encode(bmi088_acc_conf_t value)
{
    return 0;
}

inline bmi088_acc_conf_t bmi088_acc_conf_decode(uint8_t reg_value)
{
    return (bmi088_acc_conf_t){};
}

inline uint8_t bmi088_acc_fifo_data_encode(bmi088_acc_fifo_data_t value)
{
    return 0;
}

inline bmi088_acc_fifo_data_t bmi088_acc_fifo_data_decode(uint8_t reg_value)
{
    return (bmi088_acc_fifo_data_t){};
}

inline uint16_t bmi088_acc_fifo_length_encode(bmi088_acc_fifo_length_t value)
{
    return 0;
}

inline bmi088_acc_fifo_length_t bmi088_acc_fifo_length_decode(uint16_t reg_value)
{
    return (bmi088_acc_fifo_length_t){};
}

inline uint16_t bmi088_acc_temp_encode(bmi088_acc_temp_t value)
{
    return 0;
}

inline bmi088_acc_temp_t bmi088_acc_temp_decode(uint16_t reg_value)
{
    return (bmi088_acc_temp_t){};
}

inline uint8_t bmi088_acc_int_stat_encode(bmi088_acc_int_stat_t value)
{
    return 0;
}

inline bmi088_acc_int_stat_t bmi088_acc_int_stat_decode(uint8_t reg_value)
{
    return (bmi088_acc_int_stat_t){};
}

inline uint32_t bmi088_acc_sensortime_encode(bmi088_acc_sensortime_t value)
{
    return 0;
}

inline bmi088_acc_sensortime_t bmi088_acc_sensortime_decode(uint32_t reg_value)
{
    return (bmi088_acc_sensortime_t){};
}

inline uint16_t bmi088_acc_z_encode(bmi088_acc_z_t value)
{
    return 0;
}

inline bmi088_acc_z_t bmi088_acc_z_decode(uint16_t reg_value)
{
    return (bmi088_acc_z_t){};
}

inline uint16_t bmi088_acc_y_encode(bmi088_acc_y_t value)
{
    return 0;
}

inline bmi088_acc_y_t bmi088_acc_y_decode(uint16_t reg_value)
{
    return (bmi088_acc_y_t){};
}

inline uint16_t bmi088_acc_x_encode(bmi088_acc_x_t value)
{
    return 0;
}

inline bmi088_acc_x_t bmi088_acc_x_decode(uint16_t reg_value)
{
    return (bmi088_acc_x_t){};
}

inline uint8_t bmi088_acc_status_encode(bmi088_acc_status_t value)
{
    return 0;
}

inline bmi088_acc_status_t bmi088_acc_status_decode(uint8_t reg_value)
{
    return (bmi088_acc_status_t){};
}

inline uint8_t bmi088_acc_err_encode(bmi088_acc_err_t value)
{
    return 0;
}

inline bmi088_acc_err_t bmi088_acc_err_decode(uint8_t reg_value)
{
    return (bmi088_acc_err_t){};
}

inline uint8_t bmi088_acc_chip_id_encode(bmi088_acc_chip_id_t value)
{
    return 0;
}

inline bmi088_acc_chip_id_t bmi088_acc_chip_id_decode(uint8_t reg_value)
{
    return (bmi088_acc_chip_id_t){};
}

inline uint8_t bmi088_gyro_fifo_data_encode(bmi088_gyro_fifo_data_t value)
{
    return 0;
}

inline bmi088_gyro_fifo_data_t bmi088_gyro_fifo_data_decode(uint8_t reg_value)
{
    return (bmi088_gyro_fifo_data_t){};
}

inline uint16_t bmi088_gyro_fifo_config_encode(bmi088_gyro_fifo_config_t value)
{
    return 0;
}

inline bmi088_gyro_fifo_config_t bmi088_gyro_fifo_config_decode(uint16_t reg_value)
{
    return (bmi088_gyro_fifo_config_t){};
}

inline uint8_t bmi088_gyro_self_test_encode(bmi088_gyro_self_test_t value)
{
    return 0;
}

inline bmi088_gyro_self_test_t bmi088_gyro_self_test_decode(uint8_t reg_value)
{
    return (bmi088_gyro_self_test_t){};
}

inline uint8_t bmi088_gyro_fifo_ext_int_s_encode(bmi088_gyro_fifo_ext_int_s_t value)
{
    return 0;
}

inline bmi088_gyro_fifo_ext_int_s_t bmi088_gyro_fifo_ext_int_s_decode(uint8_t reg_value)
{
    return (bmi088_gyro_fifo_ext_int_s_t){};
}

inline uint8_t bmi088_gyro_fifo_wm_en_encode(bmi088_gyro_fifo_wm_en_t value)
{
    return 0;
}

inline bmi088_gyro_fifo_wm_en_t bmi088_gyro_fifo_wm_en_decode(uint8_t reg_value)
{
    return (bmi088_gyro_fifo_wm_en_t){};
}

inline uint8_t bmi088_gyro_int3_int4_io_map_encode(bmi088_gyro_int3_int4_io_map_t value)
{
    return 0;
}

inline bmi088_gyro_int3_int4_io_map_t bmi088_gyro_int3_int4_io_map_decode(uint8_t reg_value)
{
    return (bmi088_gyro_int3_int4_io_map_t){};
}

inline uint8_t bmi088_gyro_int3_int4_io_conf_encode(bmi088_gyro_int3_int4_io_conf_t value)
{
    return 0;
}

inline bmi088_gyro_int3_int4_io_conf_t bmi088_gyro_int3_int4_io_conf_decode(uint8_t reg_value)
{
    return (bmi088_gyro_int3_int4_io_conf_t){};
}

inline uint8_t bmi088_gyro_int_ctrl_encode(bmi088_gyro_int_ctrl_t value)
{
    return 0;
}

inline bmi088_gyro_int_ctrl_t bmi088_gyro_int_ctrl_decode(uint8_t reg_value)
{
    return (bmi088_gyro_int_ctrl_t){};
}

inline uint8_t bmi088_gyro_softreset_encode(bmi088_gyro_softreset_t value)
{
    return 0;
}

inline bmi088_gyro_softreset_t bmi088_gyro_softreset_decode(uint8_t reg_value)
{
    return (bmi088_gyro_softreset_t){};
}

inline uint8_t bmi088_gyro_lmp1_encode(bmi088_gyro_lmp1_t value)
{
    return 0;
}

inline bmi088_gyro_lmp1_t bmi088_gyro_lmp1_decode(uint8_t reg_value)
{
    return (bmi088_gyro_lmp1_t){};
}

inline uint8_t bmi088_gyro_bandwidth_encode(bmi088_gyro_bandwidth_t value)
{
    return 0;
}

inline bmi088_gyro_bandwidth_t bmi088_gyro_bandwidth_decode(uint8_t reg_value)
{
    return (bmi088_gyro_bandwidth_t){};
}

inline uint8_t bmi088_gyro_range_encode(bmi088_gyro_range_t value)
{
    return 0;
}

inline bmi088_gyro_range_t bmi088_gyro_range_decode(uint8_t reg_value)
{
    return (bmi088_gyro_range_t){};
}

inline uint8_t bmi088_gyro_fifo_status_encode(bmi088_gyro_fifo_status_t value)
{
    return 0;
}

inline bmi088_gyro_fifo_status_t bmi088_gyro_fifo_status_decode(uint8_t reg_value)
{
    return (bmi088_gyro_fifo_status_t){};
}

inline uint8_t bmi088_gyro_int_stat_encode(bmi088_gyro_int_stat_t value)
{
    return 0;
}

inline bmi088_gyro_int_stat_t bmi088_gyro_int_stat_decode(uint8_t reg_value)
{
    return (bmi088_gyro_int_stat_t){};
}

inline uint16_t bmi088_gyro_rate_z_encode(bmi088_gyro_rate_z_t value)
{
    return 0;
}

inline bmi088_gyro_rate_z_t bmi088_gyro_rate_z_decode(uint16_t reg_value)
{
    return (bmi088_gyro_rate_z_t){};
}

inline uint16_t bmi088_gyro_rate_y_encode(bmi088_gyro_rate_y_t value)
{
    return 0;
}

inline bmi088_gyro_rate_y_t bmi088_gyro_rate_y_decode(uint16_t reg_value)
{
    return (bmi088_gyro_rate_y_t){};
}

inline uint16_t bmi088_gyro_rate_x_encode(bmi088_gyro_rate_x_t value)
{
    return 0;
}

inline bmi088_gyro_rate_x_t bmi088_gyro_rate_x_decode(uint16_t reg_value)
{
    return (bmi088_gyro_rate_x_t){};
}

inline uint8_t bmi088_gyro_chip_id_encode(bmi088_gyro_chip_id_t value)
{
    return 0;
}

inline bmi088_gyro_chip_id_t bmi088_gyro_chip_id_decode(uint8_t reg_value)
{
    return (bmi088_gyro_chip_id_t){};
}

#endif // BMI088_BMI088_UTILITY_H