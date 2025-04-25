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
void MAX6627_ReadTemperatureReg(SPI_t *spi, unsigned char* readData)
{
    // Start tranmission
    MAX6627_StartTranmission(spi);
    // Read register 
    MAX6627_Read_Buffer(spi, readData, MAX6627_TEMP_REG_SIZE);
    // Stop tranmission
    MAX6627_EndTranmission(spi);
}