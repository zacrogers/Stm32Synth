/*
 * adxl345.h
 *
 *  Created on: May 5, 2020
 *      Author: Zac
 */

#ifndef INC_ADXL345_H_
#define INC_ADXL345_H_

#include "stm32f1xx_hal.h"
#include<stdint.h>

/* Device registers */
#define ADXL345_DEVID          (uint8_t)0x00
#define ADXL345_THRESH_TAP     (uint8_t)0x1D
#define ADXL345_X_OFFSET       (uint8_t)0x1E
#define ADXL345_Y_OFFSET       (uint8_t)0x1F
#define ADXL345_Z_OFFSET       (uint8_t)0x20
#define ADXL345_TAP_DUR        (uint8_t)0x21
#define ADXL345_TAP_LATENCY    (uint8_t)0x22
#define ADXL345_TAP_WINDOW     (uint8_t)0x23
#define ADXL345_THRESH_ACT     (uint8_t)0x24
#define ADXL345_THRESH_INACT   (uint8_t)0x25
#define ADXL345_TIME_INACT     (uint8_t)0x26
#define ADXL345_TIME_INACT_CTL (uint8_t)0x27
#define ADXL345_THRESH_FF      (uint8_t)0x28
#define ADXL345_TIME_FF        (uint8_t)0x29
#define ADXL345_TAP_AXES       (uint8_t)0x2A
#define ADXL345_ACT_TAP_STATUS (uint8_t)0x2B
#define ADXL345_BW_RATE        (uint8_t)0x2C
#define ADXL345_POWER_CTL      (uint8_t)0x2D
#define ADXL345_INT_ENABLE     (uint8_t)0x2E
#define ADXL345_INT_MAP        (uint8_t)0x2F
#define ADXL345_INT_SOURCE     (uint8_t)0x30
#define ADXL345_DATA_FORMAT    (uint8_t)0x31
#define ADXL345_DATA_X0        (uint8_t)0x32
#define ADXL345_DATA_X1        (uint8_t)0x33
#define ADXL345_DATA_Y0        (uint8_t)0x34
#define ADXL345_DATA_Y1        (uint8_t)0x35
#define ADXL345_DATA_Z0        (uint8_t)0x36
#define ADXL345_DATA_Z1        (uint8_t)0x37
#define ADXL345_FIFO_CTL       (uint8_t)0x38
#define ADXL345_FIFO_STATUS    (uint8_t)0x39


/* Power control register bits */
#define ADXL345_PWR_CTL_LINK       (uint8_t)(1U << 5)
#define ADXL345_PWR_CTL_AUTO_SLEEP (uint8_t)(1U << 4)
#define ADXL345_PWR_CTL_MEASURE    (uint8_t)(1U << 3)
#define ADXL345_PWR_CTL_SLEEP      (uint8_t)(1U << 2)
#define ADXL345_PWR_CTL_WAKEUP_1   (uint8_t)(1U << 1)
#define ADXL345_PWR_CTL_WAKEUP_0   (uint8_t)(1U << 0)


/* Data format bits */
#define ADXL345_DATA_FORMAT_SELF_TEST (uint8_t)(1U << 7)
#define ADXL345_DATA_FORMAT_SPI       (uint8_t)(1U << 6)
#define ADXL345_DATA_FORMAT_INT_INV   (uint8_t)(1U << 5)
#define ADXL345_DATA_FORMAT_FULL_RES  (uint8_t)(1U << 3)
#define ADXL345_DATA_FORMAT_JUSTIFY   (uint8_t)(1U << 2)
#define ADXL345_DATA_FORMAT_RANGE_2G  (uint8_t)(0 << 0)
#define ADXL345_DATA_FORMAT_RANGE_4G  (uint8_t)(1U << 0)
#define ADXL345_DATA_FORMAT_RANGE_8G  (uint8_t)(2U << 0)
#define ADXL345_DATA_FORMAT_RANGE_16G (uint8_t)(3U << 0)

typedef struct
{
	I2C_HandleTypeDef *i2c_bus;
	uint8_t address;
}ADXL_345;

void ADXL_345_init       (ADXL_345 *adxl_345);
void ADXL_345_write_byte (ADXL_345 *adxl_345, uint8_t val);
void ADXL_345_read       (ADXL_345 *adxl_345, uint8_t reg, uint8_t *val);
void ADXL_345_get_xyz    (ADXL_345 *adxl_345, uint8_t *xyz);




void ADXL_345_init(ADXL_345 *adxl_345)
{
	ADXL_345_write_byte(adxl_345, 0);
	ADXL_345_write_byte(adxl_345, ADXL345_PWR_CTL_AUTO_SLEEP);
	ADXL_345_write_byte(adxl_345, ADXL345_PWR_CTL_MEASURE);
}


void ADXL_345_write_byte(ADXL_345 *adxl_345, uint8_t val)
{
	uint8_t data = val;
	HAL_I2C_Master_Transmit(adxl_345->i2c_bus, adxl_345->address, (uint8_t *) &data, 1, HAL_MAX_DELAY);
}

void ADXL_345_read(ADXL_345 *adxl_345, uint8_t reg, uint8_t *val)
{
	HAL_I2C_Mem_Read(adxl_345->i2c_bus, adxl_345->address, reg,  1, (uint8_t*)val, 6, HAL_MAX_DELAY);
}

void ADXL_345_get_xyz(ADXL_345 *adxl_345, uint8_t *xyz)
{
	ADXL_345_read(adxl_345, ADXL345_DATA_X0, xyz);
}


#endif /* INC_ADXL345_H_ */
