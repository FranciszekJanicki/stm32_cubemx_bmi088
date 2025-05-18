#include "bmi088.h"
#include "bmi088_config.h"
#include "bmi088_registers.h"
#include "bmi088_utility.h"
#include <assert.h>
#include <string.h>

static bmi088_err_t bmi088_accel_init(bmi088_t const* bmi088)
{
    assert(bmi088);

    if (bmi088->interface.accel_init) {
        return bmi088->interface.accel_init(bmi088->interface.accel_user);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t bmi088_accel_deinit(bmi088_t const* bmi088)
{
    assert(bmi088);

    if (bmi088->interface.accel_deinit) {
        return bmi088->interface.accel_deinit(bmi088->interface.accel_user);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t
bmi088_accel_write(bmi088_t const* bmi088, uint8_t write_address, uint8_t const* write_data, size_t write_size)
{
    assert(bmi088 && write_data);

    if (bmi088->interface.accel_write) {
        return bmi088->interface.accel_write(bmi088->interface.accel_user, write_address, write_data, write_size);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t
bmi088_accel_read(bmi088_t const* bmi088, uint8_t read_address, uint8_t* read_data, size_t read_size)
{
    assert(bmi088 && read_data);

    if (bmi088->interface.accel_read) {
        return bmi088->interface.accel_read(bmi088->interface.accel_user, read_address, read_data, read_size);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t bmi088_gyro_init(bmi088_t const* bmi088)
{
    assert(bmi088);

    if (bmi088->interface.gyro_init) {
        return bmi088->interface.gyro_init(bmi088->interface.gyro_user);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t bmi088_gyro_deinit(bmi088_t const* bmi088)
{
    assert(bmi088);

    if (bmi088->interface.gyro_deinit) {
        return bmi088->interface.gyro_deinit(bmi088->interface.gyro_user);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t
bmi088_gyro_write(bmi088_t const* bmi088, uint8_t write_address, uint8_t const* write_data, size_t write_size)
{
    assert(bmi088 && write_data);

    if (bmi088->interface.gyro_write) {
        return bmi088->interface.gyro_write(bmi088->interface.accel_user, write_address, write_data, write_size);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t bmi088_gyro_read(bmi088_t const* bmi088, uint8_t read_address, uint8_t* read_data, size_t read_size)
{
    assert(bmi088 && read_data);

    if (bmi088->interface.gyro_read) {
        return bmi088->interface.gyro_read(bmi088->interface.accel_user, read_address, read_data, read_size);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t bmi088_delay(bmi088_t const* bmi088, uint32_t delay_ms)
{
    assert(bmi088);

    if (bmi088->interface.delay) {
        return bmi088->interface.delay(delay_ms);
    }

    return BMI088_ERR_FAIL;
}

bmi088_err_t bmi088_initialize(bmi088_t* bmi088, bmi088_config_t const* config, bmi088_interface_t const* interface)
{
    assert(bmi088 && config && interface);

    memset(bmi088, 0, sizeof(*bmi088));
    memcpy(&bmi088->config, config, sizeof(*config));
    memcpy(&bmi088->interface, interface, sizeof(*interface));

    bmi088_accel_init(bmi088);
    bmi088_gyro_init(bmi088);
}

bmi088_err_t bmi088_deinitialize(bmi088_t* bmi088)
{
    assert(bmi088);

    bmi088_accel_deinit(bmi088);
    bmi088_gyro_deinit(bmi088);

    memset(bmi088, 0, sizeof(*bmi088));
}
