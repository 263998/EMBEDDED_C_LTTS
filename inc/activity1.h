/**
 * @file activity1.h
 * @author 263998
 * @brief Configuration file to define pins and ports for the interfaced peripherals
 * @version 0.1
 * @date 2021-04-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED

/**
 * Macro Definitions
 */
#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */
#define PORT_OF_LED (PORTB)    /**< LED Port Number */
#define PIN_OF_LED  (PB1)      /**< LED Pin number  */
#define PORT_OF_SW (PORTD)     /**< SWITCH Port number */
#define PIN_OF_SW_0 (PD0)      /**< SWITCH 0 Pin number */
#define PIN_OF_SW_1 (PD1)      /**< SWITCH 1 Pin number */

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief Initialize all the Peripherals and pin configurations
 *
 */
void peripheral_init();

/**
 * @brief Main function where the code execution starts
 * @return int Return 1 if both switches are ON else returns 0
 * @note PORTB1 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB1 is in sink config. i.e when pin is High, the LED will turn ON
 * @note PORTD0 and PORTD1 have pull up register. i.e if the pins are open, the pins are inherently high
 */
int initialize_led();

#endif /* ACTIVITY1_H_INCLUDED */
