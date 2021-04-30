/**
 * @file project-config.h
 * @author Shravya K N
 * @brief Configuration file to read the temperature value using potentiometer
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef ACTIVITY2_H_INCLUDED
#define ACTIVITY2_H_INCLUDED

#include <avr/io.h>

/**
 * @brief Initializes the ADC conversion
 * @note By using suitable division factor ADC gets initialised
 */
void InitADC();

/**
 * @brief Function where the ADC conversion happens
 * @param [in] uint_8t value is taken as input analog value for the conversion
 * @return returns uint16_t integer as digital value for the given analog value.
 * @note PORTC0 is connected to potentiometer, according to the obtained value conversion is done and returns corresponding analog value
 */
uint16_t ReadADC(uint8_t);

#endif // ACTIVITY2_H_INCLUDED
