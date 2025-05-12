#ifndef BMI088_CONFIG_HPP
#define BMI088_CONFIG_HPP

#include <cstdint>

namespace bmi088 {

    namespace accel {

        enum struct RegAddr : std::uint8_t {
            ACC_SOFTRESET = 0x7E,
            ACC_PWR_CTRL = 0x7D,
            ACC_SELF_TEST = 0x6D,
            INT_MAP_DATA = 0x58,
            INT2_IO_CTRL = 0x54,
            INT1_IO_CTRL = 0x53,
            FIFO_CONFIG_1 = 0x49,
            FIFO_CONFIG_0 = 0x48,
            FIFO_WTM_1 = 0x47,
            FIFO_WTM_0 = 0x46,
            FIFO_DOWNS = 0x45,
            ACC_RANGE = 0x41,
            ACC_CONF = 0x40,
            FIFO_DATA = 0x26,
            FIFO_LENGTH_1 = 0x25,
            FIFO_LENGTH_0 = 0x24,
            TEMP_LSB = 0x23,
            TEMP_MSB = 0x22,
            ACC_INT_STAT = 0x1D,
            SENSORTIME_2 = 0x1A,
            SENSORTIME_1 = 0x19,
            SENSORTIME_0 = 0x18,
            ACC_Z_MSB = 0x17,
            ACC_Z_LSB = 0x16,
            ACC_Y_MSB = 0x15,
            ACC_Y_LSB = 0x14,
            ACC_X_MSB = 0x13,
            ACC_X_LSB = 0x12,
            ACC_STATUS = 0x03,
            ACC_ERR_REG = 0x02,
            ACC_CHIP_ID = 0x00,
        };

        enum struct PowerMode : std::uint8_t {
            NORMAL_MODE,
            SUSPEND_MODE,
        };

        enum struct ODR : std::uint8_t {
            ODR_12HZ5,
            ODR_25HZ,
            ODR_50HZ,
            ODR_100HZ,
            ODR_200HZ,
            ODR_400HZ,
            ODR_800HZ,
            ODR_1600HZ,
        };

        enum struct SlaveAddr : std::uint8_t {
            SD01_GND = 0b0011000,
            SD01_VDDIO = 0b0011001,
        };

        constexpr auto TEMP_SCALE = 0.125F32;

        constexpr auto ACC_PERIOD_INC_US = 39.0625F32;

    }; // namespace accel

    namespace gyro {

        enum struct RegAddr : std::uint8_t {
            FIFO_DATA = 0x3F,
            FIFO_CONFIG_1 = 0x3E,
            FIFO_CONFIG_0 = 0x3D,
            GYRO_SELF_TEST = 0x3C,
            FIFO_EXT_INT_S = 0x34,
            FIFO_WM_EN = 0x1E,
            INT3_INT4_IO_MAP = 0x18,
            INT3_INT4_IO_CONF = 0x16,
            GYRO_INT_CTRL = 0x15,
            GYRO_SOFTRESET = 0x14,
            GYRO_LPM1 = 0x11,
            GYRO_BANDWIDTH = 0x10,
            GYRO_RANGE = 0x0F,
            FIFO_STATUS = 0x0E,
            GYRO_INT_STAT = 0x0A,
            RATE_Z_MSB = 0x07,
            RATE_Z_LSB = 0x06,
            RATE_Y_MSB = 0x05,
            RATE_Y_LSB = 0x04,
            RATE_X_MSB = 0x03,
            RATE_X_LSB = 0x02,
            GYRO_CHIP_ID = 0x00,
        };

        enum struct PowerMode : std::uint8_t {
            NORMAL_MODE,
            SUSPEND_MODE,
            DEEP_SUSPEND_MODE,
        };

        enum struct ODR : std::uint8_t {

        };

        enum struct SlaveAddr : std::uint8_t {
            SDO2_GND = 0b1101000,
            SD02_VDDIO = 0b1101001,
        };

    }; // namespace gyro

    struct Config {};

    struct Interface {
        void* accel_user;
        void* gyro_user;
        void (*init)(void* const);
        void (*deinit)(void* const);
        void (*write)(void* const, std::uint8_t const, std::uint8_t const* const, std::size_t const);
        void (*read)(void* const, std::uint8_t const, std::uint8_t* const, std::size_t const);
        void (*delay)(void* const, std::uint32_t const);
    };

}; // namespace bmi088

#endif // BMI088_CONFIG_HPP