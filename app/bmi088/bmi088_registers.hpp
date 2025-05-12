#ifndef BMI088_REGISTERS_HPP
#define BMI088_REGISTERS_HPP

#include <cstdint>

#define PACKED __attribute__((packed))

namespace bmi088 {

    namespace accel {

        struct ACC_SOFTRESET {
            std::uint8_t softreset : 8;
        } PACKED;

        struct ACC_PWR_CTRL {
            std::uint8_t acc_enable : 8;
        } PACKED;

        struct ACC_PWR_CONF {
            std::uint8_t pwr_save_mode : 8;
        } PACKED;

        struct ACC_SELF_TEST {
            std::uint8_t acc_self_test : 8;
        } PACKED;

        struct INT_MAP_DATA {
            std::uint8_t : 1;
            std::uint8_t int2_drdy : 1;
            std::uint8_t int2_fwm : 1;
            std::uint8_t int2_ffull : 1;
            std::uint8_t : 1;
            std::uint8_t int1_drdy : 1;
            std::uint8_t int1_fwm : 1;
            std::uint8_t int1_ffull : 1;
        } PACKED;

        struct INT2_IO_CTRL {
            std::uint8_t : 3;
            std::uint8_t int2_in : 1;
            std::uint8_t int2_out : 1;
            std::uint8_t int2_od : 1;
            std::uint8_t int2_lvl : 1;
            std::uint8_t : 1;
        } PACKED;

        struct INT1_IO_CTRL {
            std::uint8_t : 3;
            std::uint8_t int1_in : 1;
            std::uint8_t int1_out : 1;
            std::uint8_t int1_od : 1;
            std::uint8_t int1_lvl : 1;
            std::uint8_t : 1;
        } PACKED;

        struct FIFO_CONFIG {
            std::uint8_t : 1;
            std::uint8_t acc_en : 1;
            std::uint8_t : 1;
            std::uint8_t reserved : 1 = 1;
            std::uint8_t int1_en : 1;
            std::uint8_t int2_en : 1;
            std::uint8_t : 2;
        } PACKED;

        struct FIFO_WTM {
            std::uint8_t : 3;
            std::uint16_t fifo_water_mark : 13;
        } PACKED;

        struct FIFO_DOWNS {
            std::uint8_t : 1;
            std::uint8_t fifo_downs : 2;
            std::uint8_t : 5;
        } PACKED;

        struct ACC_RANGE {
            std::uint8_t : 6;
            std::uint8_t acc_range : 2;
        } PACKED;

        struct ACC_CONF {
            std::uint8_t acc_bwp : 4;
            std::uint8_t acc_odr : 4;
        } PACKED;

        struct FIFO_DATA {
            std::uint8_t fifo_data : 8;
        } PACKED;

        struct FIFO_LENGTH {
            std::uint8_t : 2;
            std::uint16_t length : 14;
        } PACKED;

        struct TEMP {
            std::uint16_t temperature_lsb : 3;
            std::uint16_t : 5;
            std::uint16_t temperature_msb : 8;
        } PACKED;

        struct ACC_INT_STAT {
            std::uint8_t acc_drdy : 1;
            std::uint8_t : 7;
        } PACKED;

        struct SENSORTIME {
            std::uint32_t sensor_time : 24;
        } PACKED;

        struct ACC_Z {
            std::uint8_t acc_z_lsb : 8;
            std::uint8_t acc_z_msb : 8;
        } PACKED;

        struct ACC_Y {
            std::uint8_t acc_y_lsb : 8;
            std::uint8_t acc_y_msb : 8;
        } PACKED;

        struct ACC_X {
            std::uint8_t acc_x_lsb : 8;
            std::uint8_t acc_x_msb : 8;
        } PACKED;

        struct ACC_STATUS {
            std::uint8_t acc_drdy : 1;
            std::uint8_t : 7;
        } PACKED;

        struct ACC_ERR_REG {
            std::uint8_t : 3;
            std::uint8_t error_code : 3;
            std::uint8_t : 1;
            std::uint8_t fatal_err : 1;
        } PACKED;

        struct ACC_CHIP_ID {
            std::uint8_t acc_chip_id : 8;
        } PACKED;

    }; // namespace accel

    namespace gyro {

        struct FIFO_DATA {
            std::uint8_t fifo_data_output : 8;
        } PACKED;

        struct FIFO_CONFIG {
            std::uint8_t fifo_mode : 1;
            std::uint8_t : 7;
            std::uint8_t fifo_wm_lvl_trig_retain : 8;
        } PACKED;

        struct GYRO_SELF_TEST {
            std::uint8_t : 3;
            std::uint8_t rate_ok : 1;
            std::uint8_t : 1;
            std::uint8_t bist_fail : 1;
            std::uint8_t bist_rdy : 1;
            std::uint8_t trig_bist : 1;
        } PACKED;

        struct FIFO_EXT_INT_S {
            std::uint8_t : 2;
            std::uint8_t ext_fifo_s_en : 1;
            std::uint8_t ext_fifo_s_sel : 1;
            std::uint8_t : 4;
        } PACKED;

        struct FIFO_WM_EN {
            std::uint8_t fifo_wm_en : 8;
        } PACKED;

        struct INT3_INT4_IO_MAP {
            std::uint8_t int4_data : 1;
            std::uint8_t : 1;
            std::uint8_t int4_fifo : 1;
            std::uint8_t : 2;
            std::uint8_t int3_fifo : 1;
            std::uint8_t : 1;
            std::uint8_t int3_data : 1;
        } PACKED;

        struct INT3_INT4_IO_CONF {
            std::uint8_t : 4;
            std::uint8_t int4_od : 1;
            std::uint8_t int4_lvl : 1;
            std::uint8_t int3_od : 1;
            std::uint8_t int3_lvl : 1;
        } PACKED;

        struct GYRO_INT_CTRL {
            std::uint8_t date_en : 1;
            std::uint8_t fifo_en : 1;
            std::uint8_t : 6;
        } PACKED;

        struct GYRO_SOFTRESET {
            std::uint8_t softreset : 8;
        } PACKED;

        struct GYRO_LPM1 {
            std::uint8_t gyro_pm : 8;
        } PACKED;

        struct GYRO_BANDWIDTH {
            std::uint8_t gyro_bw : 8;
        } PACKED;

        struct GYRO_RANGE {
            std::uint8_t gyro_range : 8;
        } PACKED;

        struct FIFO_STATUS {
            std::uint8_t fifo_overrun : 1;
            std::uint8_t fifo_frame_counter : 7;
        } PACKED;

        struct GYRO_INT_STAT {
            std::uint8_t gyro_drdy : 1;
            std::uint8_t : 2;
            std::uint8_t fifo_int : 1;
            std::uint8_t : 4;
        } PACKED;

        struct RATE_Z {
            std::uint8_t rate_z_lsb : 8;
            std::uint8_t rate_z_msb : 8;
        } PACKED;

        struct RATE_Y {
            std::uint8_t rate_y_lsb : 8;
            std::uint8_t rate_y_msb : 8;
        } PACKED;

        struct RATE_X {
            std::uint8_t rate_x_lsb : 8;
            std::uint8_t rate_x_msb : 8;
        } PACKED;

        struct GYRO_CHIP_ID {
            std::uint8_t gyro_chip_id : 8;
        } PACKED;

    }; // namespace gyro

}; // namespace bmi088

#undef PACKED

#endif // BMI088_REGISTERS_HPP