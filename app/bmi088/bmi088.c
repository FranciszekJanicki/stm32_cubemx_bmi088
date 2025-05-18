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

    return BMI088_ERR_FAIL;
}

static bmi088_err_t bmi088_acc_deinit(bmi088_t const* bmi088)
{
    assert(bmi088);

    if (bmi088->interface.acc_deinit) {
        return bmi088->interface.acc_deinit(bmi088->interface.acc_user);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t
bmi088_acc_write(bmi088_t const* bmi088, uint8_t write_address, uint8_t const* write_data, size_t write_size)
{
    assert(bmi088);
    assert(write_data);

    if (bmi088->interface.acc_write) {
        return bmi088->interface.acc_write(bmi088->interface.acc_user, write_address, write_data, write_size);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t bmi088_acc_read(bmi088_t const* bmi088, uint8_t read_address, uint8_t* read_data, size_t read_size)
{
    assert(bmi088);
    assert(read_data);

    if (bmi088->interface.acc_read) {
        return bmi088->interface.acc_read(bmi088->interface.acc_user, read_address, read_data, read_size);
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
    assert(bmi088);
    assert(write_data);

    if (bmi088->interface.gyro_write) {
        return bmi088->interface.gyro_write(bmi088->interface.acc_user, write_address, write_data, write_size);
    }

    return BMI088_ERR_FAIL;
}

static bmi088_err_t bmi088_gyro_read(bmi088_t const* bmi088, uint8_t read_address, uint8_t* read_data, size_t read_size)
{
    assert(bmi088);
    assert(read_data);

    if (bmi088->interface.gyro_read) {
        return bmi088->interface.gyro_read(bmi088->interface.acc_user, read_address, read_data, read_size);
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

    bmi088_acc_init(bmi088);
    bmi088_gyro_init(bmi088);
}

bmi088_err_t bmi088_deinitialize(bmi088_t* bmi088)
{
    assert(bmi088);

    bmi088_acc_deinit(bmi088);
    bmi088_gyro_deinit(bmi088);

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

bmi088_err_t bmi088_set_acc_softreset_reg(bmi088_t const* bmi088, bmi088_acc_softreset_t reg)
{
    uint8_t data = reg.softreset;
    return bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_SOFTRESET, &data, sizeof(data));
}

bmi088_err_t bmi088_set_acc_pwr_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_pwr_ctrl_t reg)
{
    uint8_t data = reg.acc_enable & 0xFF;
    bmi088_err_t err = bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_PWR_CTRL, &data, sizeof(data));

    return err;
}

bmi088_err_t bmi088_get_acc_pwr_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_pwr_ctrl_t* reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_PWR_CTRL, &data, sizeof(data));

    *reg = (bmi088_acc_pwr_ctrl_t){.acc_enable = data & 0xFF};

    return err;
}

bmi088_err_t bmi088_set_acc_pwr_conf_reg(bmi088_t const* bmi088, bmi088_acc_pwr_conf_t reg)
{
    uint8_t data = reg.pwr_save_mode & 0xFF;
    bmi088_err_t err = bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_PWR_CONF, &data, sizeof(data));

    return err;
}

bmi088_err_t bmi088_get_acc_pwr_conf_reg(bmi088_t const* bmi088, bmi088_acc_pwr_conf_t* reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_PWR_CONF, &data, sizeof(data));

    *reg = (bmi088_acc_pwr_conf_t){.pwr_save_mode = data & 0xFF};

    return err;
}

bmi088_err_t bmi088_set_acc_self_test_reg(bmi088_t const* bmi088, bmi088_acc_self_test_t reg)
{
    uint8_t data = reg.acc_self_test & 0xFF;

    bmi088_err_t err = bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_ACC_SELF_TEST, &data, sizeof(data));

    return err;
}

bmi088_err_t bmi088_get_acc_self_test_reg(bmi088_t const* bmi088, bmi088_acc_self_test_t* reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_SELF_TEST, &data, sizeof(data));

    *reg = (bmi088_acc_self_test_t){.acc_self_test = data & 0xFF};

    return err;
}

bmi088_err_t bmi088_set_acc_int_map_data_reg(bmi088_t const* bmi088, bmi088_acc_int_map_data_t reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT_MAP_DATA, &data, sizeof(data));

    data &= ~((1 << 6) | (1 << 5) | (1 << 4) | (1 << 2) | (1 << 1) | 1);
    data |= ((reg.int2_drdy & 1) << 6) | ((reg.int2_fwm & 1) << 5) | ((reg.int2_ffull & 1) << 4) |
            ((reg.int1_drdy & 1) << 2) | ((reg.int1_fwm & 1) << 1) | (reg.int1_ffull & 1);

    err = bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_INT_MAP_DATA, &data, sizeof(data));

    return err;
}

bmi088_err_t bmi088_get_acc_int_map_data_reg(bmi088_t const* bmi088, bmi088_acc_int_map_data_t* reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_ACC_SELF_TEST, &data, sizeof(data));

    *reg = (bmi088_acc_int_map_data_t){.int2_drdy = (data >> 6) & 1,
                                       .int2_fwm = (data >> 5) & 1,
                                       .int2_ffull = (data >> 4) & 1,
                                       .int1_drdy = (data >> 2) & 1,
                                       .int1_fwm = (data >> 1) & 1,
                                       .int1_ffull = data & 1};

    return err;
}

bmi088_err_t bmi088_set_acc_int2_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int2_io_ctrl_t reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT2_IO_CTRL, &data, sizeof(data));

    data &= ~((1 << 4) | (1 << 3) | (1 << 2) | (1 << 1));
    data |= ((reg.int2_in & 1) << 4) | ((reg.int2_out & 1) << 3) | ((reg.int2_od & 1) << 2) | ((reg.int2_lvl & 1) << 1);

    err = bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_INT2_IO_CTRL, &data, sizeof(data));

    return err;
}

bmi088_err_t bmi088_get_acc_int2_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int2_io_ctrl_t* reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT2_IO_CTRL, &data, sizeof(data));

    *reg = (bmi088_acc_int2_io_ctrl_t){.int2_in = (data >> 4) & 1,
                                       .int2_out = (data >> 3) & 1,
                                       .int2_od = (data >> 2) & 1,
                                       .int2_lvl = (data >> 1) & 1};

    return err;
}

bmi088_err_t bmi088_set_acc_int1_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int1_io_ctrl_t reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT1_IO_CTRL, &data, sizeof(data));

    data &= ~((1 << 4) | (1 << 3) | (1 << 2) | (1 << 1));
    data |= ((reg.int1_in & 1) << 4) | ((reg.int1_out & 1) << 3) | ((reg.int1_od & 1) << 2) | ((reg.int1_lvl & 1) << 1);

    err = bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_INT1_IO_CTRL, &data, sizeof(data));

    return err;
}

bmi088_err_t bmi088_get_acc_int1_io_ctrl_reg(bmi088_t const* bmi088, bmi088_acc_int1_io_ctrl_t* reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_INT1_IO_CTRL, &data, sizeof(data));

    *reg = (bmi088_acc_int1_io_ctrl_t){.int1_in = (data >> 4) & 1,
                                       .int1_out = (data >> 3) & 1,
                                       .int1_od = (data >> 2) & 1,
                                       .int1_lvl = (data >> 1) & 1};

    return err;
}

bmi088_err_t bmi088_set_acc_fifo_config_1_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_1_t reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_CONFIG_1, &data, sizeof(data));

    data &= ~((1 << 6) | (1 << 3) | (1 << 2));
    data |= ((reg.acc_en & 1) << 6) | ((reg.int1_en & 1) << 3) | ((reg.int2_en) << 2);

    err = bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_FIFO_CONFIG_1, &data, sizeof(data));

    return err;
}

bmi088_err_t bmi088_get_acc_fifo_config_1_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_1_t* reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_CONFIG_1, &data, sizeof(data));

    *reg =
        (bmi088_acc_fifo_config_1_t){.acc_en = (data >> 6) & 1, .int1_en = (data >> 3) & 1, .int2_en = (data >> 2) & 1};

    return err;
}

bmi088_err_t bmi088_set_acc_fifo_config_0_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_0_t reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_CONFIG_0, &data, sizeof(data));

    data &= ~(1 << 0);
    data |= (reg.mode & 1);

    err = bmi088_acc_write(bmi088, BMI088_ACC_REG_ADDR_FIFO_CONFIG_0, &data, sizeof(data));

    return err;
}

bmi088_err_t bmi088_get_acc_fifo_config_0_reg(bmi088_t const* bmi088, bmi088_acc_fifo_config_0_t* reg)
{
    uint8_t data;
    bmi088_err_t err = bmi088_acc_read(bmi088, BMI088_ACC_REG_ADDR_FIFO_CONFIG_0, &data, sizeof(data));

    *reg = (bmi088_acc_fifo_config_0_t){.mode = data & 1};

    return err;
}

bmi088_err_t bmi088_set_acc_fifo_wtm_reg(bmi088_t const* bmi088, bmi088_acc_fifo_wtm_t reg)
{}

bmi088_err_t bmi088_set_acc_fifo_downs_reg(bmi088_t const* bmi088, bmi088_acc_fifo_downs_t reg)
{}

bmi088_err_t bmi088_get_acc_fifo_downs_reg(bmi088_t const* bmi088, bmi088_acc_fifo_downs_t* reg)
{}

bmi088_err_t bmi088_set_acc_range_reg(bmi088_t const* bmi088, bmi088_acc_range_t reg)
{}

bmi088_err_t bmi088_get_acc_range_reg(bmi088_t const* bmi088, bmi088_acc_range_t* reg)
{}

bmi088_err_t bmi088_get_acc_conf_reg(bmi088_t const* bmi088, bmi088_acc_conf_t* reg)
{}

bmi088_err_t bmi088_set_acc_conf_reg(bmi088_t const* bmi088, bmi088_acc_conf_t reg)
{}

bmi088_err_t bmi088_get_acc_fifo_data_reg(bmi088_t const* bmi088, bmi088_acc_fifo_data_t* reg)
{}

bmi088_err_t bmi088_get_acc_fifo_length_1_reg(bmi088_t const* bmi088, bmi088_acc_fifo_length_1_t* reg)
{}

bmi088_err_t bmi088_get_acc_fifo_length_0_reg(bmi088_t const* bmi088, bmi088_acc_fifo_length_0_t* reg)
{}

bmi088_err_t bmi088_get_acc_temp_lsb_reg(bmi088_t const* bmi088, bmi088_acc_temp_lsb_t* reg)
{}

bmi088_err_t bmi088_get_acc_temp_msb_reg(bmi088_t const* bmi088, bmi088_acc_temp_lsb_t* reg)
{}

bmi088_err_t bmi088_get_acc_int_stat_reg(bmi088_t const* bmi088, bmi088_acc_int_stat_t* reg)
{}

bmi088_err_t bmi088_get_acc_sensortime_2_reg(bmi088_t const* bmi088, bmi088_acc_sensortime_2_t* reg)
{}

bmi088_err_t bmi088_get_acc_sensortime_1_reg(bmi088_t const* bmi088, bmi088_acc_sensortime_1_t* reg)
{}

bmi088_err_t bmi088_get_acc_sensortime_0_reg(bmi088_t const* bmi088, bmi088_acc_sensortime_0_t* reg)
{}

bmi088_err_t bmi088_get_acc_z_msb_reg(bmi088_t const* bmi088, bmi088_acc_z_msb_t* reg)
{}

bmi088_err_t bmi088_get_acc_z_lsb_reg(bmi088_t const* bmi088, bmi088_acc_z_lsb_t* reg)
{}

bmi088_err_t bmi088_get_acc_y_msb_reg(bmi088_t const* bmi088, bmi088_acc_y_msb_t* reg)
{}

bmi088_err_t bmi088_get_acc_y_lsb_reg(bmi088_t const* bmi088, bmi088_acc_y_lsb_t* reg)
{}

bmi088_err_t bmi088_get_acc_x_msb_reg(bmi088_t const* bmi088, bmi088_acc_x_msb_t* reg)
{}

bmi088_err_t bmi088_get_acc_x_lsb_reg(bmi088_t const* bmi088, bmi088_acc_x_lsb_t* reg)
{}

bmi088_err_t bmi088_get_acc_status_reg(bmi088_t const* bmi088, bmi088_acc_status_t* reg)
{}

bmi088_err_t bmi088_get_acc_err_reg(bmi088_t const* bmi088, bmi088_acc_err_t* reg)
{}

bmi088_err_t bmi088_get_acc_chip_id_reg(bmi088_t const* bmi088, bmi088_acc_chip_id_t* reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_data_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_data_t* reg)
{}

bmi088_err_t bmi088_set_gyro_fifo_config_1_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_1_t reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_config_1_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_1_t* reg)
{}

bmi088_err_t bmi088_set_gyro_fifo_config_0_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_0_t reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_config_0_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_config_0_t* reg)
{}

bmi088_err_t bmi088_set_gyro_self_test_reg(bmi088_t const* bmi088, bmi088_gyro_self_test_t reg)
{}

bmi088_err_t bmi088_get_gyro_self_test_reg(bmi088_t const* bmi088, bmi088_gyro_self_test_t* reg)
{}

bmi088_err_t bmi088_set_gyro_fifo_ext_int_s_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_ext_int_s_t reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_ext_int_s_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_ext_int_s_t* reg)
{}

bmi088_err_t bmi088_set_gyro_fifo_wtm_en_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_wm_en_t reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_wtm_en_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_wm_en_t* reg)
{}

bmi088_err_t bmi088_set_gyro_int3_int4_io_map_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_map_t reg)
{}

bmi088_err_t bmi088_get_gyro_int3_int4_io_map_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_map_t* reg)
{}

bmi088_err_t bmi088_set_gyro_int3_int4_io_conf_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_conf_t reg)
{}

bmi088_err_t bmi088_get_gyro_int3_int4_io_conf_reg(bmi088_t const* bmi088, bmi088_gyro_int3_int4_io_conf_t* reg)
{}

bmi088_err_t bmi088_set_gyro_int_ctrl_reg(bmi088_t const* bmi088, bmi088_gyro_int_ctrl_t reg)
{}

bmi088_err_t bmi088_get_gyro_int_ctrl_reg(bmi088_t const* bmi088, bmi088_gyro_int_ctrl_t* reg)
{}

bmi088_err_t bmi088_set_gyro_softreset_reg(bmi088_t const* bmi088, bmi088_gyro_softreset_t* reg)
{}

bmi088_err_t bmi088_set_gyro_lmp1_reg(bmi088_t const* bmi088, bmi088_gyro_lmp1_t reg)
{}

bmi088_err_t bmi088_get_gyro_lmp1_reg(bmi088_t const* bmi088, bmi088_gyro_lmp1_t* reg)
{}

bmi088_err_t bmi088_set_gyro_bandwidth_reg(bmi088_t const* bmi088, bmi088_gyro_bandwidth_t reg)
{}

bmi088_err_t bmi088_get_gyro_bandwidth_reg(bmi088_t const* bmi088, bmi088_gyro_bandwidth_t* reg)
{}

bmi088_err_t bmi088_set_gyro_range_reg(bmi088_t const* bmi088, bmi088_gyro_range_t reg)
{}

bmi088_err_t bmi088_get_gyro_range_reg(bmi088_t const* bmi088, bmi088_gyro_range_t* reg)
{}

bmi088_err_t bmi088_get_gyro_fifo_status_reg(bmi088_t const* bmi088, bmi088_gyro_fifo_status_t* reg)
{}

bmi088_err_t bmi088_get_get_gyro_int_stat_reg(bmi088_t const* bmi088, bmi088_gyro_int_stat_t* reg)
{}

bmi088_err_t bmi088_get_gyro_rate_z_msb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_z_msb_t* reg)
{}

bmi088_err_t bmi088_get_gyro_rate_z_lsb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_z_lsb_t* reg)
{}

bmi088_err_t bmi088_get_gyro_rate_y_msb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_y_msb_t* reg)
{}

bmi088_err_t bmi088_get_gyro_rate_y_lsb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_y_lsb_t* reg)
{}

bmi088_err_t bmi088_get_gyro_rate_x_msb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_x_msb_t* reg)
{}

bmi088_err_t bmi088_get_gyro_rate_x_lsb_reg(bmi088_t const* bmi088, bmi088_gyro_rate_x_lsb_t* reg)
{}

bmi088_err_t bmi088_gyro_chip_id_reg(bmi088_t const* bmi088, bmi088_gyro_chip_id_t* reg)
{}
