#include "bmi088.h"
#include "bmi088_config.h"
#include "bmi088_registers.h"
#include "bmi088_utility.h"
#include <assert.h>
#include <string.h>

static bmi088_err_t bmi088_acc_init(bmi088_t const* bmi088)
{
    assert(bmi088);

    if (bmi088->interface.acc_init) {
        return bmi088->interface.acc_init(bmi088->interface.acc_user);
    }

    return BMI0088_ERR_NULL;
}

static bmi088_err_t bmi088_acc_deinit(bmi088_t const* bmi088)
{
    assert(bmi088);

    if (bmi088->interface.acc_deinit) {
        return bmi088->interface.acc_deinit(bmi088->interface.acc_user);
    }

    return BMI0088_ERR_NULL;
}

static bmi088_err_t
bmi088_acc_write(bmi088_t const* bmi088, uint8_t write_address, uint8_t const* write_data, size_t write_size)
{
    assert(bmi088);
    assert(write_data);

    if (bmi088->interface.acc_write) {
        return bmi088->interface.acc_write(bmi088->interface.acc_user, write_address, write_data, write_size);
    }

    return BMI0088_ERR_NULL;
}

static bmi088_err_t bmi088_acc_read(bmi088_t const* bmi088, uint8_t read_address, uint8_t* read_data, size_t read_size)
{
    assert(bmi088);
    assert(read_data);

    if (bmi088->interface.acc_read) {
        return bmi088->interface.acc_read(bmi088->interface.acc_user, read_address, read_data, read_size);
    }

    return BMI0088_ERR_NULL;
}

static bmi088_err_t bmi088_gyro_init(bmi088_t const* bmi088)
{
    assert(bmi088);

    if (bmi088->interface.gyro_init) {
        return bmi088->interface.gyro_init(bmi088->interface.gyro_user);
    }

    return BMI0088_ERR_NULL;
}

static bmi088_err_t bmi088_gyro_deinit(bmi088_t const* bmi088)
{
    assert(bmi088);

    if (bmi088->interface.gyro_deinit) {
        return bmi088->interface.gyro_deinit(bmi088->interface.gyro_user);
    }

    return BMI0088_ERR_NULL;
}

static bmi088_err_t
bmi088_gyro_write(bmi088_t const* bmi088, uint8_t write_address, uint8_t const* write_data, size_t write_size)
{
    assert(bmi088);
    assert(write_data);

    if (bmi088->interface.gyro_write) {
        return bmi088->interface.gyro_write(bmi088->interface.gyro_user, write_address, write_data, write_size);
    }

    return BMI0088_ERR_NULL;
}

static bmi088_err_t bmi088_gyro_read(bmi088_t const* bmi088, uint8_t read_address, uint8_t* read_data, size_t read_size)
{
    assert(bmi088);
    assert(read_data);

    if (bmi088->interface.gyro_read) {
        return bmi088->interface.gyro_read(bmi088->interface.gyro_user, read_address, read_data, read_size);
    }

    return BMI0088_ERR_NULL;
}

static bmi088_err_t bmi088_delay(bmi088_t const* bmi088, uint32_t delay_ms)
{
    assert(bmi088);

    if (bmi088->interface.delay) {
        return bmi088->interface.delay(delay_ms);
    }

    return BMI0088_ERR_NULL;
}

bmi088_err_t bmi088_initialize(bmi088_t* bmi088, bmi088_config_t const* config, bmi088_interface_t const* interface)
{
    assert(bmi088 && config && interface);

    memset(bmi088, 0, sizeof(*bmi088));
    memcpy(&bmi088->config, config, sizeof(*config));
    memcpy(&bmi088->interface, interface, sizeof(*interface));

    bmi088_err_t err = bmi088_acc_init(bmi088);
    if (err != BMI088_ERR_OK) {
        return err;
    }

    return bmi088_gyro_init(bmi088);
}

bmi088_err_t bmi088_deinitialize(bmi088_t* bmi088)
{
    assert(bmi088);

    bmi088_err_t err = bmi088_acc_deinit(bmi088);
    if (err != BMI088_ERR_OK) {
        return err;
    }

    err = bmi088_gyro_deinit(bmi088);
    if (err != BMI088_ERR_OK) {
        return err;
    }

    memset(bmi088, 0, sizeof(*bmi088));
}

bmi088_err_t bmi088_get_acc_data_raw(bmi088_t const* bmi088, bmi088_data_raw_t* raw)
{}

bmi088_err_t bmi088_get_acc_data_scaled(bmi088_t const* bmi088, bmi088_data_scaled_t* scaled)
{}

bmi088_err_t bmi088_get_gyro_data_raw(bmi088_t const* bmi088, bmi088_data_raw_t* raw)
{}

bmi088_err_t bmi088_get_gyro_data_scaled(bmi088_t const* bmi088, bmi088_data_scaled_t* scaled)
{}

bmi088_err_t bmi088_get_temp_data_raw(bmi088_t const* bmi088, int16_t* raw)
{}

bmi088_err_t bmi088_get_temp_data_scaled(bmi088_t const* bmi088, float32_t* scaled)
{}

bmi088_err_t bmi088_set_acc_softreset_reg(bmi088_t const* bmi088, bmi088_acc_softreset_reg_t* reg)
{
    uint8_t data = {};

    data = (reg->softreset & 0xFFU) << 0U;

    return bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_SOFTRESET, &data, sizeof(data));
}

bmi088_err_t bmi088_set_acc_pwr_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_pwr_ctrl_reg_t* reg)
{
    uint8_t data = {};

    data = (reg->acc_enable & 0xFFU) << 0U;

    return bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_PWR_CTRL, &data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_pwr_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_pwr_ctrl_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_PWR_CTRL, &data, sizeof(data));

    reg->acc_enable = (data >> 0U) & 0xFFU;

    return err;
}

bmi088_err_t bmi088_set_acc_pwr_conf_reg(bmi088_t const* bmi088, bmi088_acc_pwr_conf_reg_t* reg)
{
    uint8_t data = {};

    data = (reg->pwr_save_mode & 0xFFU) << 0U;

    return bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_PWR_CONF, &data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_pwr_conf_reg(bmi088_t const* bmi088, bmi088_acc_pwr_conf_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_PWR_CONF, &data, sizeof(data));

    reg->pwr_save_mode = (data >> 0U) & 0xFFU;

    return err;
}

bmi088_err_t bmi088_set_acc_self_test_reg(bmi088_t const* bmi088, bmi088_acc_self_test_reg_t* reg)
{
    uint8_t data = {};

    data = (reg->acc_self_test & 0xFFU) << 0U;

    return bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_SELF_TEST, &data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_self_test_reg(bmi088_t const* bmi088, bmi088_acc_self_test_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_SELF_TEST, &data, sizeof(data));

    reg->acc_self_test = (data >> 0U) & 0xFFU;

    return err;
}

bmi088_err_t bmi088_set_acc_int_map_data_reg(bmi088_t const* bmi088, bmi088_acc_int_map_data_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT_MAP_DATA, &data, sizeof(data));

    data &= ~(1U << 6U);
    data &= ~(1U << 5U);
    data &= ~(1U << 4U);
    data &= ~(1U << 2U);
    data &= ~(1U << 1U);
    data &= ~(1U << 0U);

    data |= (reg->int2_drdy & 0x01U) << 6U;
    data |= (reg->int2_fwm & 0x01U) << 5U;
    data |= (reg->int2_ffull & 0x01U) << 4U;
    data |= (reg->int1_drdy & 0x01U) << 2U;
    data |= (reg->int1_fwm & 0x01U) << 1U;
    data |= (reg->int1_ffull & 0x01U) << 0U;

    return err != BMI088_ERR_OK ? err : bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_INT_MAP_DATA, &data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_int_map_data_reg(bmi088_t const* bmi088, bmi088_acc_int_map_data_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_SELF_TEST, &data, sizeof(data));

    reg->int2_drdy = (data >> 6U) & 0x01U;
    reg->int2_fwm = (data >> 5U) & 0x01U;
    reg->int2_ffull = (data >> 4U) & 0x01U;
    reg->int1_drdy = (data >> 2U) & 0x01U;
    reg->int1_fwm = (data >> 1U) & 0x01U;
    reg->int1_ffull = (data >> 0U) & 0x01U;

    return err;
}

bmi088_err_t bmi088_set_acc_int2_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int2_io_ctrl_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT2_IO_CTRL, &data, sizeof(data));

    data &= ~(1U << 4U);
    data &= ~(1U << 3U);
    data &= ~(1U << 2U);
    data &= ~(1U << 1U);

    data |= (reg->int2_in & 0x01U) << 4U;
    data |= (reg->int2_out & 0x01U) << 3U;
    data |= (reg->int2_od & 0x01U) << 2U;
    data |= (reg->int2_lvl & 0x01U) << 1U;

    return err != BMI088_ERR_OK ? err : bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_INT2_IO_CTRL, &data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_int2_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int2_io_ctrl_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT2_IO_CTRL, &data, sizeof(data));

    reg->int2_in = (data >> 4U) & 0x01U;
    reg->int2_out = (data >> 3U) & 0x01U;
    reg->int2_od = (data >> 2U) & 0x01U;
    reg->int2_lvl = (data >> 1U) & 0x01U;

    return err;
}

bmi088_err_t bmi088_set_acc_int1_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int1_io_ctrl_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT1_IO_CTRL, &data, sizeof(data));

    data &= ~(1U << 4U);
    data &= ~(1U << 3U);
    data &= ~(1U << 2U);
    data &= ~(1U << 1U);

    data |= (reg->int1_in & 0x01U) << 4U;
    data |= (reg->int1_out & 0x01U) << 3U;
    data |= (reg->int1_od & 0x01U) << 2U;
    data |= (reg->int1_lvl & 0x01U) << 1U;

    return err != BMI088_ERR_OK ? err : bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_INT1_IO_CTRL, &data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_int1_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int1_io_ctrl_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT1_IO_CTRL, &data, sizeof(data));

    reg->int1_in = (data >> 4U) & 0x01U;
    reg->int1_out = (data >> 3U) & 0x01U;
    reg->int1_od = (data >> 2U) & 0x01U;
    reg->int1_lvl = (data >> 1U) & 0x01U;

    return err;
}

bmi088_err_t bmi088_set_acc_fifo_config_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_reg_t* reg)
{
    uint8_t data[2] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_CONFIG_0, data, sizeof(data));
    if (err != BMI088_ERR_OK) {
        return err;
    }

    data[0] &= ~(1U << 0U);
    data[1] &= ~(1U << 6U);
    data[1] &= ~(1U << 3U);
    data[1] &= ~(1U << 2U);

    data[0] |= (reg->mode & 0x01U) << 0U;
    data[1] |= (reg->acc_en & 0x01U) << 6U;
    data[1] |= (reg->int1_en & 0x01U) << 3U;
    data[1] |= (reg->int2_en & 0x01U) << 2U;

    return err != BMI088_ERR_OK ? err : bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_FIFO_CONFIG_0, data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_fifo_config_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_reg_t* reg)
{
    uint8_t data[2] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_CONFIG_0, data, sizeof(data));

    reg->acc_en = (data[0] >> 6U) & 0x01U;
    reg->int1_en = (data[0] >> 3U) & 0x01U;
    reg->int2_en = (data[0] >> 2U) & 0x01U;
    reg->mode = (data[1] >> 0U) & 0x01U;

    return err;
}

bmi088_err_t bmi088_set_acc_fifo_wtm_reg(bmi088_t const* bmi088, bmi088_acc_fifo_wtm_reg_t* reg)
{
    uint8_t data[2] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_WTM_0, data, sizeof(data));

    data[0] &= ~0xFFU;
    data[1] &= ~0x1FU;

    data[0] |= (reg->fifo_water_mark_7to0 & 0xFFU) << 0U;
    data[1] |= (reg->fifo_water_mark_8to_12 & 0x1FU) << 0U;

    return err != BMI088_ERR_OK ? err : bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_FIFO_WTM_0, data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_fifo_wtm_reg(bmi088_t const* bmi088, bmi088_acc_fifo_wtm_reg_t* reg)
{
    uint8_t data[2] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_WTM_0, data, sizeof(data));

    reg->fifo_water_mark_7to0 = (data[0] >> 0U) & 0xFFU;
    reg->fifo_water_mark_8to_12 = (data[1] >> 0U) & 0x1FU;

    return err;
}

bmi088_err_t bmi088_set_acc_fifo_downs_reg(bmi088_t const* bmi088, bmi088_acc_fifo_downs_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_DOWNS, &data, sizeof(data));

    data &= ~0x60U;
    data |= (reg->fifo_downs & 0x03U) << 5U;

    return err != BMI088_ERR_OK ? err : bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_FIFO_WTM_0, &data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_fifo_downs_reg(bmi088_t const* bmi088, bmi088_acc_fifo_downs_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_WTM_0, &data, sizeof(data));

    reg->fifo_downs = (data >> 5U) & 0x03U;

    return err;
}

bmi088_err_t bmi088_set_acc_range_reg(bmi088_t const* bmi088, bmi088_acc_range_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_RANGE, &data, sizeof(data));

    data &= ~0x03;
    data |= (reg->acc_range & 0x03U) << 0U;

    return err != BMI088_ERR_OK ? err : bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_RANGE, &data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_range_reg(bmi088_t const* bmi088, bmi088_acc_range_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_RANGE, &data, sizeof(data));

    reg->acc_range = (data >> 0U) & 0x03U;

    return err;
}

bmi088_err_t bmi088_set_acc_conf_reg(bmi088_t const* bmi088, bmi088_acc_conf_reg_t* reg)
{
    uint8_t data = {};

    data |= (reg->acc_bwp & 0x0FU) << 4U;
    data |= (reg->acc_odr & 0x0FU) << 0U;

    return bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_CONF, &data, sizeof(data));
}

bmi088_err_t bmi088_get_acc_conf_reg(bmi088_t const* bmi088, bmi088_acc_conf_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_CONF, &data, sizeof(data));

    reg->acc_bwp = (data >> 4U) & 0x0FU;
    reg->acc_odr = (data >> 0U) & 0x0FU;

    return err;
}

bmi088_err_t bmi088_get_acc_fifo_data_reg(bmi088_t const* bmi088, bmi088_acc_fifo_data_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_DATA, &data, sizeof(data));

    reg->fifo_data = (data >> 0U) & 0xFFU;

    return err;
}

bmi088_err_t bmi088_get_acc_fifo_length_reg(bmi088_t const* bmi088, bmi088_acc_fifo_length_reg_t* reg)
{
    uint8_t data[2] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_DATA, data, sizeof(data));

    reg->fifo_byte_counter_7to0 = (data[0] >> 0U) & 0xFFU;
    reg->fifo_byte_counter_13to8 = (data[1] >> 0U) & 0x3FU;

    return err;
}

bmi088_err_t bmi088_get_acc_temp_reg(bmi088_t const* bmi088, bmi088_acc_temp_reg_t* reg)
{
    uint8_t data[2] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_TEMP_MSB, data, sizeof(data));

    reg->temperature_10to3 = (data[0] >> 0U) & 0xFFU;
    reg->temperature_2to0 = (data[1] >> 5U) & 0x07U;

    return err;
}

bmi088_err_t bmi088_get_acc_int_stat_reg(bmi088_t const* bmi088, bmi088_acc_int_stat_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_INT_STAT, &data, sizeof(data));

    reg->acc_drdy = (data >> 7U) & 0x01U;

    return err;
}

bmi088_err_t bmi088_get_acc_sensortime_reg(bmi088_t const* bmi088, bmi088_acc_sensortime_reg_t* reg)
{
    uint8_t data[3] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_SENSORTIME_0, data, sizeof(data));

    reg->sensor_time_7to0 = (data[0] >> 0U) & 0xFFU;
    reg->sensor_time_15to8 = (data[1] >> 0U) & 0xFFU;
    reg->sensor_time_23to16 = (data[2] >> 0U) & 0xFFU;

    return err;
}

bmi088_err_t bmi088_get_acc_z_reg(bmi088_t const* bmi088, bmi088_acc_z_reg_t* reg)
{
    uint8_t data[2] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_Z_LSB, data, sizeof(data));

    reg->acc_z_7to0 = (data[0] >> 0U) & 0xFFU;
    reg->acc_z_15to8 = (data[1] >> 0U) & 0xFFU;

    return err;
}

bmi088_err_t bmi088_get_acc_y_reg(bmi088_t const* bmi088, bmi088_acc_y_reg_t* reg)
{
    uint8_t data[2] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_Y_LSB, data, sizeof(data));

    reg->acc_y_7to0 = (data[0] >> 0U) & 0xFFU;
    reg->acc_y_15to8 = (data[1] >> 0U) & 0xFFU;

    return err;
}

bmi088_err_t bmi088_get_acc_x_reg(bmi088_t const* bmi088, bmi088_acc_x_reg_t* reg)
{
    uint8_t data[2] = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_X_LSB, data, sizeof(data));

    reg->acc_x_7to0 = (data[0] >> 0U) & 0xFFU;
    reg->acc_x_15to8 = (data[1] >> 0U) & 0xFFU;

    return err;
}

bmi088_err_t bmi088_get_acc_status_reg(bmi088_t const* bmi088, bmi088_acc_status_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_STATUS, &data, sizeof(data));

    reg->drdy_acc = (data >> 7U) & 0x01U;

    return err;
}

bmi088_err_t bmi088_get_acc_err_reg(bmi088_t const* bmi088, bmi088_acc_err_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_ERR_REG, &data, sizeof(data));

    reg->error_code = (data >> 2U) & 0x08U;
    reg->fatal_err = (data >> 0U) & 0x01U;

    return err;
}

bmi088_err_t bmi088_get_acc_chip_id_reg(bmi088_t const* bmi088, bmi088_acc_chip_id_reg_t* reg)
{
    uint8_t data = {};

    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_CHIP_ID, &data, sizeof(data));

    reg->acc_chip_id = (data >> 0U) & 0xFFU;

    return err;
}

bmi088_err_t bmi088_get_gyro_fifo_data_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_data_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_fifo_config_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_config_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_self_test_reg(bmi088_t const* bmi088, bmi088_gyro_self_test_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_self_test_reg(bmi088_t const* bmi088, bmi088_gyro_self_test_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_fifo_ext_int_s_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_ext_int_s_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_ext_int_s_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_ext_int_s_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_fifo_wtm_en_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_wm_en_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_wtm_en_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_wm_en_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_int3_int4_io_map_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_map_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_int3_int4_io_map_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_map_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_int3_int4_io_conf_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_conf_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_int3_int4_io_conf_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_conf_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_int_ctrl_reg(bmi088_t const* bmi088, bmi088_gyro_int_ctrl_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_int_ctrl_reg(bmi088_t const* bmi088, bmi088_gyro_int_ctrl_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_softreset_reg(bmi088_t const* bmi088, bmi088_gyro_softreset_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_lmp1_reg(bmi088_t const* bmi088, bmi088_gyro_lmp1_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_lmp1_reg(bmi088_t const* bmi088, bmi088_gyro_lmp1_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_bandwidth_reg(bmi088_t const* bmi088, bmi088_gyro_bandwidth_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_bandwidth_reg(bmi088_t const* bmi088, bmi088_gyro_bandwidth_reg_t* reg)
{}

bmi088_err_t bmi088_set_gyro_range_reg(bmi088_t const* bmi088, bmi088_gyro_range_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_range_reg(bmi088_t const* bmi088, bmi088_gyro_range_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_status_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_status_reg_t* reg)
{}

bmi088_err_t bmi088_get_get_gyro_int_stat_reg(bmi088_t const* bmi088, bmi088_gyro_int_stat_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_rate_z_reg(bmi088_t const* bmi088, bmi088_gyro_rate_z_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_rate_y_reg(bmi088_t const* bmi088, bmi088_gyro_rate_y_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_rate_x_reg(bmi088_t const* bmi088, bmi088_gyro_rate_x_reg_t* reg)
{}

bmi088_err_t bmi088_get_gyro_chip_id_reg(bmi088_t const* bmi088, bmi088_gyro_chip_id_reg_t* reg)
{}
