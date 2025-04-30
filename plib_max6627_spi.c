/**
 * @file plib_max6627_spi.c
 * @brief Pilote SPI pour le MAX6927 (capteur de température)
 * @author Ramiro Najera
 * @version 1.0.1
 * @date 2025-04-24
 * @copyright Copyright (c) 2025
 */

#include "plib_max6627_spi.h"
#include "peripheral/spi/spi_master/plib_spi2_master.h"
#include "peripheral/spi/spi_master/plib_spi1_master.h"

void MAX6627_Read_Byte(SPI_t *spi, unsigned char* data)
{
    if(spi->channel == SPI_CH1)
        SPI1_Read(data, 1);
    else if(spi->channel == SPI_CH2)
        SPI2_Read(data, 1);
}

void MAX6627_Read_Buffer(SPI_t *spi, unsigned char* data, unsigned int size)
{
    unsigned char i;
    
    for(i = 0; i < size; i++)
    {
        MAX6627_Read_Byte(spi, &data[i]);
    } 
}