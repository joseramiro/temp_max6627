#include "plib_max6627.h"
#include "plib_max6627_spi.h"

void MAX6627_StartTranmission(SPIConfiguration_t *spi)
{
    spi->cs.clear();
}

void MAX6627_EndTranmission(SPIConfiguration_t *spi)
{
    spi->cs.set();
}

// Basic functions
void MAX6627_ReadTemperatureReg(SPIConfiguration_t *spi, unsigned char* readData)
{
    // Start tranmission
    MAX6627_StartTranmission(spi);
    // Read register 
    MAX6627_Read_Buffer(spi, readData, MAX6627_TEMP_REG_SIZE);
    // Stop tranmission
    MAX6627_EndTranmission(spi);
}