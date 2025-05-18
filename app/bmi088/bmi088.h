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

// bmi088_err_t bmi088_get_acc_data_raw(bmi088_t const* bmi088, bmi088_data_raw_t* raw);
// bmi088_err_t bmi088_get_acc_data_scaled(bmi088_t const* bmi088, bmi088_data_scaled_t* scaled);

// bmi088_err_t bmi088_get_gyro_data_raw(bmi088_t const* bmi088, bmi088_data_raw_t* raw);
// bmi088_err_t bmi088_get_gyro_data_scaled(bmi088_t const* bmi088, bmi088_data_scaled_t* scaled);

// bmi088_err_t bmi088_get_acc_softreset(bmi088_t const* bmi088, uint8_t* softreset);
// bmi088_err_t bmi088_set_acc_softreset(bmi088_t const* bmi088, uint8_t softreset);

// bmi088_err_t bmi088_get_acc_enable(bmi088_t const* bmi088, uint8_t* enable);
// bmi088_err_t bmi088_set_acc_enable(bmi088_t const* bmi088, uint8_t enable);

// bmi088_err_t bmi088_get_acc_pwr_save_mode(bmi088_t const* bmi088, uint8_t* pwr_save_mode);
// bmi088_err_t bmi088_set_acc_pwr_save_mode(bmi088_t const* bmi088, uint8_t pwr_save_mode);

// bmi088_err_t bmi088_get_acc_self_test(bmi088_t const* bmi088, uint8_t* self_test);
// bmi088_err_t bmi088_set_acc_self_test(bmi088_t const* bmi088, uint8_t self_test);

// bmi088_err_t bmi088_get_acc_int2_data_ready(bmi088_t const* bmi088, bool* int2_data_ready);

#endif // BMI088_BMI088_H