#include <avr/io.h>
#include<avr/delay.h>
#include "external_interrupt.h"
volatile int Flag=0;

int main()
{
external_interrupt();
    // Insert code
    DDRD&=~(1<<3);
    PORTD|=(1<<3);
    DDRB|=(1<<7);
    sei();

    while(1)
        if(Flag==1)
        {
            PORTB|=(1<<7);
            _delay_ms(2000);
            Flag=0;
        }
        else
            PORTB&=~(1<<7);


    return 0;
}
ISR(INT1_vect)
{
    Flag=1;
}
