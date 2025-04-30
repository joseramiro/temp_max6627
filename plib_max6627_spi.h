#ifndef PLIB_MAX6627_SPI_H
#define PLIB_MAX6627_SPI_H

/**
 * @file plib_max6627_spi.h
 * @brief Pilote SPI pour le MAX6927 (capteur de température)
 * @author Ramiro Najera
 * @version 1.0.1
 * @date 2025-04-24
 * @copyright Copyright (c) 2025
 */

#include "libs/common_c_libs/plib_comm_struct.h"

/**
 * @brief Lit des données dans le MAX6627 via SPI.
 * @param spi Pointeur vers la configuration SPI utilisée pour la communication.
 * @param data Donnée à lire
 */
void MAX6627_Read_Byte(SPI_t *spi, unsigned char* data);

/**
 * @brief Lit des données dans le MAX6627 via SPI.
 * @param spi Pointeur vers la configuration SPI utilisée pour la communication.
 * @param data Donnée à lire
 * @param size Taille de données à lire
 */

void MAX6627_Read_Buffer(SPI_t *spi, unsigned char* data, unsigned int size);

#endif  // PLIB_MAX6627_SPI_H