#include "activity4.h"

int i = 0;

void USARTInit(uint16_t ubrr_value){
    //Set Baud rate
    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&0x00ff;
    UCSR0C = (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);

    //Enable the receiver and transmitter
    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0);
}

char USARTReadChar(){
    //Wait until data is available
    while(!(UCSR0A & (1<<RXC0))){
        //Do nothing
    }
    return UDR0;
}

void USARTWriteChar(uint16_t temp){
    if(temp>=0 && temp<=200){
        unsigned char temperature[] = "Temperature is 20 degree Celsius"; /*duty cycle is 20%*/
        i = 0;
        while(temperature[i] != 0) /*print the String*/
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];            /*Put data into buffer, sends the data*/
            i++;                             /*increment counter*/
        }
    }
    else if(temp>=210 && temp<=500){
        unsigned char temperature[] = "Temperature is 25 degree Celsius"; /*duty cycle is 40%*/
        i = 0;
        while(temperature[i] != 0) /*print the String*/
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];            /*Put data into buffer, sends the data*/
            i++;                             /*increment counter*/
        }
    }
    else if(temp>=510 && temp<=700){
        unsigned char temperature[] = "Temperature is 29 degree Celsius"; /*duty cycle is 70%*/
        i = 0;
        while(temperature[i] != 0) /*print the String*/
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];            /*Put data into buffer, sends the data*/
            i++;                             /*increment counter*/
        }
    }
    else if(temp>=710 && temp<=1024){
        unsigned char temperature[] = "Temperature is 33 degree Celsius"; /*duty cycle is 95%*/
        i = 0;
        while(temperature[i] != 0) /*print the String*/
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];            /*Put data into buffer, sends the data*/
            i++;                             /*increment counter*/
        }
    }
    else{
        unsigned char temperature[] = "Temperature is not within the limit";  /*duty cycle is 100%*/
        i = 0;
        while(temperature[i] != 0) /*print the String*/
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];            /*Put data into buffer, sends the data*/
            i++;                             /*increment counter*/
        }
    }
    while (!( UCSR0A & (1<<UDRE0)));   /*Wait for empty transmit buffer*/
		 UDR0 = '\n';   /*Put data into buffer, sends the data*/
    while (!( UCSR0A & (1<<UDRE0)));   /*Wait for empty transmit buffer*/
		 UDR0 = '\r';					    /*Put data into buffer, sends the data*/
    _delay_ms(2000);
}
