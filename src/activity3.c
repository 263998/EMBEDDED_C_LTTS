#include "activity3.h"

void setup_pwm()
{
    TCCR1A |= (1<<COM1A1) | (1<<WGM11) | (1<<WGM10); /*set non-inverting mode and waveform generation of 10-bit Fast PWM mode is selected*/
    TCCR1B |= (1<<WGM12) | (1<<CS11) | (1<<CS10);   /*prescalar is 64*/
    DDRB |= (1<<PB1);   /*initializing portb1 for observing PWM*/
}

void pwm_waveform(uint16_t temp){
    if(temp >= 0 && temp <= 200){
        OCR1A = 0xcc; /*duty cycle is 20%*/
    }
    else if(temp >= 210 && temp <= 500){
        OCR1A = 0x199;  /*duty cycle is 40%*/
    }
    else if(temp >= 510 && temp <= 700){
        OCR1A = 0x2cc;  /*duty cycle is 70%*/
    }
    else if(temp >= 710 && temp <= 1024){
        OCR1A = 0x3cb;  /*duty cycle is 95%*/
    }
    else{
        OCR1A = 0x3ff;  /*duty cycle is 100%*/
    }
}
