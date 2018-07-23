#include <xc.h>

#define HFINTOSC 6

void delay() {
    for (int i = 0; i < 20000; i++) {}
}

void main(void) {
    
    /* 1. Select high frequency internal oscillator(HFINTOSC) as the source */
    OSCCON2 |= (HFINTOSC << 4);
    
    /* 2. Configure pin RB0 as output(default) */
    TRISB &= ~(1 << 0);
    
    /* 3. Toggle the voltage on pin RB0 repeatedly */
    while (1) {
        LATB |= (1 << 0);
        delay();
        LATB &= ~(1 << 0);
        delay();
    }
    
    return;
}
