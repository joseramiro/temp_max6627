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
    if(spi->channel == SPI_CH1)
        SPI1_Read(data, size);
    else if(spi->channel == SPI_CH2)
        SPI2_Read(data, size); 
}