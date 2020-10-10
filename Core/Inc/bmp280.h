/*
 * bmp280.h
 *
 *  Created on: May 6, 2020
 *      Author: Zac
 */

#ifndef INC_BMP280_H_
#define INC_BMP280_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>

/* Registers */
#define BMP280_ID         (uint8_t) 0xD0
#define BMP280_RESET      (uint8_t) 0xE0
#define BMP280_STATUS     (uint8_t) 0xF3
#define BMP280_CTRL_MEAS  (uint8_t) 0xF4
#define BMP280_CONFIG     (uint8_t) 0xF5
#define BMP280_PRESS_MSB  (uint8_t) 0xF7
#define BMP280_PRESS_LSB  (uint8_t) 0xF8
#define BMP280_PRESS_XLSB (uint8_t) 0xF9
#define BMP280_TEMP_MSB   (uint8_t) 0xFA
#define BMP280_TEMP_LSB   (uint8_t) 0xFB
#define BMP280_TEMP_XLSB  (uint8_t) 0xFC

/* Id register */
#define BMP280_ID_RESET_STATE (uint8_t) 0x58

/* Status Register */
#define BMP280_STATUS_MEASURING (uint8_t) (1U << 3)
#define BMP280_STATUS_IM_UPDATE (uint8_t) (1U << 0)

/* Ctrl meas register */
// Pressure oversampling
#define BMP280_PRESS_OS_1  (uint8_t) (1U << 2)
#define BMP280_PRESS_OS_2  (uint8_t) (2U << 2)
#define BMP280_PRESS_OS_4  (uint8_t) (3U << 2)
#define BMP280_PRESS_OS_8  (uint8_t) (4U << 2)
#define BMP280_PRESS_OS_16 (uint8_t) (5U << 2)

// Temperature oversampling
#define BMP280_TEMP_OS_1  (uint8_t) (1U << 5)
#define BMP280_TEMP_OS_2  (uint8_t) (2U << 5)
#define BMP280_TEMP_OS_4  (uint8_t) (3U << 5)
#define BMP280_TEMP_OS_8  (uint8_t) (4U << 5)
#define BMP280_TEMP_OS_16 (uint8_t) (5U << 5)

// Power mode
#define BMP280_PWR_SLEEP  (uint8_t) ~(2U << 0)
#define BMP280_PWR_FORCE  (uint8_t) (1U << 0)
#define BMP280_PWR_NORM   (uint8_t) (3U << 0)

/* Config register */
// Standby time
#define BMP280_SB_0_5_MS  (uint8_t) ~(3U << 5)
#define BMP280_SB_62_5_MS (uint8_t) (1U << 5)
#define BMP280_SB_125_MS  (uint8_t) (2U << 5)
#define BMP280_SB_250_MS  (uint8_t) (3U << 5)
#define BMP280_SB_500_MS  (uint8_t) (4U << 5)
#define BMP280_SB_1000_MS (uint8_t) (5U << 5)
#define BMP280_SB_2000_MS (uint8_t) (6U << 5)
#define BMP280_SB_4000_MS (uint8_t) (7U << 5)

// Filter time constant
#define BMP280_F_COEFF_0  (uint8_t) ~(3U << 2)
#define BMP280_F_COEFF_2  (uint8_t) (1U << 2)
#define BMP280_F_COEFF_4  (uint8_t) (2U << 2)
#define BMP280_F_COEFF_8  (uint8_t) (3U << 2)
#define BMP280_F_COEFF_16 (uint8_t) (4U << 2)

// Spi enable
#define BMP280_SPI_ENABLE (uint8_t) (1U << 0)


typedef struct
{
	I2C_HandleTypeDef *i2c_bus;
	uint8_t address;
}BMP280;

void BMP280_init(BMP280 *bmp280);

void BMP280_read_reg(BMP280 *bmp280, uint8_t reg);
void BMP280_write_reg(BMP280 *bmp280, uint8_t reg);

void BMP280_read_temp(BMP280 *bmp280);
void BMP280_read_pressure(BMP280 *bmp280);
void BMP280_read_temp(BMP280 *bmp280);

void BMP280_set_pressure_oversampling(BMP280 *bmp280, uint8_t mode);
void BMP280_set_temp_oversampling(BMP280 *bmp280, uint8_t mode);
void BMP280_set_power_mode(BMP280 *bmp280, uint8_t mode);
void BMP280_set_standby(BMP280 *bmp280, uint8_t standby_time);
void BMP280_set_filter_coeff(BMP280 *bmp280, uint8_t coeff);

void BMP280_enable_spi(BMP280 *bmp280);

#endif /* INC_BMP280_H_ */
