#include "activity2.h"

void InitADC(){
ADMUX=(1<<REFS0);   /*aref connected to AVCC*/
ADCSRA=(1<<ADEN)|(7<<ADPS0);    /*ADEN=1 => enable ADC; division factor=128*/
}

uint16_t ReadADC(uint8_t ch){
ADMUX &= 0xf8;
ch = ch&0b00000111; /*channel 0 i.e. PORTC0*/
ADMUX |= ch;    /*select a particular ADC channel(i.e. 0 in this case)*/
ADCSRA |= (1<<ADSC);    /*start Analog to Digital conversion*/
while(!(ADCSRA & (1<<ADIF)))    /*wait until the conversion is done*/
    ADCSRA |= (1<<ADIF);
return(ADC);    /*return the result*/
}
