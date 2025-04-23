#ifndef PLIB_MAX6627_SPI_H
#define PLIB_MAX6627_SPI_H

#include "libs/common_c_libs/plib_comm_struct.h"

#define MAX6627_DUMMY_DATA      0xFF

void MAX6627_Read_Byte(SPI_t *spi, unsigned char* data);
void MAX6627_Read_Buffer(SPI_t *spi, unsigned char* data, unsigned int size);

#endif  // PLIB_MAX6627_SPI_H