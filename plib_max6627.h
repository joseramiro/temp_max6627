#ifndef PLIB_MAX6627_H
#define PLIB_MAX6627_H

#include "libs/util/plibs_utils.h"  // used for SPI struct

#define MAX6627_TEMP_REG_SIZE   2

/**
 * @struct TempSensorConf
 * @brief Configuration d'un capteur de température MAX31723
 * 
 * Cette structure définit les paramètres de configuration pour un module MAX31723
 */
typedef struct
{
    unsigned char id;   /**< Identifiant du module (voir @ref FansMax31723IdList) */
    SPIConfiguration_t spi;
}MAX6627Conf_t;

/**
 * @brief Démarre une transmission SPI avec le module MAX31723.
 * @param spi Pointeur vers la configuration SPI utilisée pour la communication.
 */
void MAX6627_StartTranmission(SPIConfiguration_t *spi);

/**
 * @brief Termine une transmission SPI avec le module MAX31723.
 * @param spi Pointeur vers la configuration SPI utilisée pour la communication.
 */
void MAX6627_EndTranmission(SPIConfiguration_t *spi);

void MAX6627_ReadTemperatureReg(SPIConfiguration_t *spi, unsigned char* readData);

#endif  // PLIB_MAX31723_H