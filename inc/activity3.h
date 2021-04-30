/**
 * @file project-config.h
 * @author Shravya K N
 * @brief Configuration file to show PWM output according to temperature value
 * @version 0.1
 * @date 2021-04-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef ACTIVITY3_H_INCLUDED
#define ACTIVITY3_H_INCLUDED

#include <avr/io.h>

/**
 * @brief Initialize all the Peripherals and pin configurations for pwm
 * @note PORTB1 is given to oscilloscope for observing the waveform as channel A is selected
 * @note Pre-scaler is set to 64 by using CS11 and CS10
 * @note 10-bit Fast PWM is set by using WGM12, WGM11 and WGM10
 */
void setup_pwm();

/**
 * @brief Generating PWM waveform according to the value of temperature(ADC)
 * @param[in] uint16_t value is sent as input to initiate PWM according to the value
 * @note For 0-200 ADC value duty cycle of PWM is 20% denotes 20 degree Celsius
 * @note For 210-500 ADC value duty cycle of PWM is 40% denotes 25 degree Celsius
 * @note For 510-700 ADC value duty cycle of PWM is 70% denotes 29 degree Celsius
 * @note For 710-1024 ADC value duty cycle of PWM is 95% denotes 33 degree Celsius
 * @note For any other ADC value duty cycle of PWM is 100%
 */
void pwm_waveform(uint16_t);

#endif // ACTIVITY3_H_INCLUDED
