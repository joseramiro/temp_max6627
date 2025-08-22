/**
 * @file plib_max6627.c
 * @brief Pilote pour le MAX6927 (capteur de température)
 * @author Ramiro Najera
 * @version 1.0.2
 * @date 2025-04-24
 * @copyright Copyright (c) 2025
 */

#include <string.h>
#include "plib_max6627.h"
#include "plib_max6627_spi.h"

void MAX6627_StartTranmission(SPI_t *spi)
{
    if(spi->en.clear != NULL)
        spi->en.clear();
    if(spi->cs.clear != NULL) 
        spi->cs.clear();
}

void MAX6627_EndTranmission(SPI_t *spi)
{
    if(spi->cs.set != NULL)
        spi->cs.set();
    if(spi->en.set != NULL)
        spi->en.set();
}

// Basic functions
void MAX6627_ReadTemperatureReg(SPI_t *spi, unsigned char* readData)
{
    // Start tranmission
    MAX6627_StartTranmission(spi);
    // Read register 
    MAX6627_Read_Buffer(spi, readData, MAX6627_TEMP_REG_SIZE);
    // Stop tranmission
    MAX6627_EndTranmission(spi);
}

void MAX6627_UpdateTemperature(MAX6627_t* obj)
{
    unsigned char rawTemperature[2];
    union IntUsCharUnion convertedTemperature;

    // Read raw register
    MAX6627_ReadTemperatureReg(&obj->spi, rawTemperature);
    memcpy(&convertedTemperature.IntValue, &rawTemperature, 2);

    // Right shift (bit 2-bit 0 from register unused)
    convertedTemperature.IntValue = (convertedTemperature.IntValue >> 3);

    // Sign-extend 13-bit value (bit 12 is the sign bit)
    if (convertedTemperature.IntValue & MAX6627_SIGNESS_MASK)  // If negative
    {
        //rawData.IntValue |= 0xFFFFE000;  // Sign-extend to 32 bits
        convertedTemperature.IntValue |= MAX6627_TEMPERATURE_MASK;  // Sign-extend to 16 bits
    }

    // Update temperature vlaue in float
    obj->temperature = convertedTemperature.IntValue * MAX6627_TEMP_COEFF;
}

float MAX6627_GetTemperature(MAX6627_t* obj)
{
    return obj->temperature;
}