/**
 * @file plib_max6627.c
 * @brief Pilote pour le MAX6927 (capteur de température)
 * @author Ramiro Najera
 * @version 1.0.0
 * @date 2025-04-24
 * @copyright Copyright (c) 2025
 */

#include "plib_max6627.h"
#include "plib_max6627_spi.h"

void MAX6627_StartTranmission(SPI_t *spi)
{
    spi->cs.clear();
}

void MAX6627_EndTranmission(SPI_t *spi)
{
    spi->cs.set();
}

// Basic functions
void MAX6627_ReadTemperatureReg(SPI_t *spi, union IntUsCharUnion* readData)
{
    // Start tranmission
    MAX6627_StartTranmission(spi);
    // Read register 
    MAX6627_Read_Buffer(spi, &readData->usChar[0], MAX6627_TEMP_REG_SIZE);
    // Stop tranmission
    MAX6627_EndTranmission(spi);
}

void MAX6627_UpdateTemperature(MAX6627_t obj)
{
    union IntUsCharUnion rawData;

    // Read raw register
    MAX6627_ReadTemperatureReg(&obj.spi, &rawData);

    // Right shift (bit 2-bit 0 from register unused)
    rawData.IntValue = (rawData.IntValue >> 3);

    // Sign-extend 13-bit value (bit 12 is the sign bit)
    if (rawData.IntValue & 0x1000)  // If negative
    {
        //rawData.IntValue |= 0xFFFFE000;  // Sign-extend to 32 bits
        rawData.IntValue |= 0xF000;      // Sign-extend to 16 bits
    }

    // Update temperature vlaue in float
    obj.temperature = rawData.IntValue * MAX6627_TEMP_COEFF;
}

float MAX6627_GetTemperature(MAX6627_t obj)
{
    return obj.temperature;
}