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

inline uint8_t bmi088_acc_selt_test_encode(bmi088_acc_selt_test_t value)
{
    return (value.acc_self_test & 0xFF);
}

inline bmi088_acc_selt_test_t bmi088_acc_selt_test_decode(uint8_t reg_value)
{
    return (bmi088_acc_selt_test_t){.acc_self_test = (reg_value & 0xFF)};
}

inline uint8_t bmi088_acc_int_map_data_encode(bmi088_acc_int_map_data_t value)
{
    return ((value.reserved7 & 0x01) << 7) | ((value.int2_drdy & 0x01) << 6) | ((value.int2_fwm & 0x01) << 5) |
           ((value.int2_ffull & 0x01) << 4) | ((value.reserved3 & 0x01) << 3) | ((value.int1_drdy & 0x01) << 2) |
           ((value.int1_fwm & 0x01) << 1) | (value.int1_ffull & 0x01);
}

inline bmi088_acc_int_map_data_t bmi088_acc_int_map_data_decode(uint8_t reg_value)
{
    return (bmi088_acc_int_map_data_t){.reserved7 = ((reg_value >> 7) & 0x01),
                                       .int2_drdy = ((reg_value >> 6) & 0x01),
                                       .int2_fwm = ((reg_value >> 5) & 0x01),
                                       .int2_ffull = ((reg_value >> 4) & 0x01),
                                       .reserved3 = ((reg_value >> 3) & 0x01),
                                       .int1_drdy = ((reg_value >> 2) & 0x01),
                                       .int1_fwm = ((reg_value >> 1) & 0x01),
                                       .int1_ffull = (reg_value & 0x01)};
}

inline uint8_t bmi088_acc_int2_io_ctrl_encode(bmi088_acc_int2_io_ctrl_t value)
{
    return ((value.reserved765 & 0x07) << 5) | ((value.int2_in & 0x01) << 4) | ((value.int2_out & 0x01) << 3) |
           ((value.int2_od & 0x01) << 2) | ((value.int2_lvl & 0x01) << 1) | (value.reserved0 & 0x01);
}

#endif // BMI088_BMI088_UTILITY_H