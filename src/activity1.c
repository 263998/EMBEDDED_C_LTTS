#include "activity1.h"

void peripheral_init(void)
{
	/* Configure LED Pin */
	DDRB |= (1<<PIN_OF_LED);
	/* Configure Switch1 pin as Output */
	DDRD &= ~(1<<PIN_OF_SW_0);
    PORT_OF_SW |= (1<<PIN_OF_SW_0);
	/* Configure Switch2 pin as Output */
    DDRD &= ~(1<<PIN_OF_SW_1);
    PORT_OF_SW |= (1<<PIN_OF_SW_1);
}

int initialize_led(){
    /* Check if both Switch is closed; i.e Pins 0 and 1 of port D is low*/
    if(!(PIND&(1<<PIN_OF_SW_0)) && !(PIND&(1<<PIN_OF_SW_1))){
        /* Turn on LED */
        PORT_OF_LED |= (1<<PIN_OF_LED);
        _delay_ms(2000);
        return 1;
    }
    else{
        PORT_OF_LED &= ~(1<<PIN_OF_LED);
        /* Turn off LED*/
        _delay_ms(2000);
        return 0;
    }
}

