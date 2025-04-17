#ifndef PLIB_MAX6627_SPI_H
#define PLIB_MAX6627_SPI_H

#include "libs/util/plibs_utils.h"  // used for SPI struct

#define MAX6627_DUMMY_DATA      0xFF

void MAX6627_Read_Byte(SPIConfiguration_t *spi, unsigned char* data);
void MAX6627_Read_Buffer(SPIConfiguration_t *spi, unsigned char* data, unsigned int size);

#endif  // PLIB_MAX6627_SPI_H