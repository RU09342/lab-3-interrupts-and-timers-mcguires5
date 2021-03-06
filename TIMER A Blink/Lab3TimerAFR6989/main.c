#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= (BIT0);
    P9DIR |= BIT7;
    P1OUT &= 0x00; // Set the LEDs off
    P9OUT &= ~BIT7;


        TB0CCTL0 = CCIE;   // CCR0 interrupt enabled
        TBCTL = TBSSEL_2 + MC_1 + ID_3; // SMCLK/8, UPMODE


        TBCCR0 = 0xFFFF; // CCR0 = 65535 is the number that the clock counts to
        //1250000/8 = 156250
        //65535/156250 = 0.4 so the led toggles every 0.4 seconds
        __enable_interrupt();

        __bis_SR_register(LPM0 + GIE); // LPM0 with interrupts enabled


}


#pragma vector=TIMER0_B0_VECTOR
__interrupt void Timer0_B0 (void)
{

    P1OUT ^= (BIT0); // Toggles LEDS
    P9OUT ^= BIT7;
}
