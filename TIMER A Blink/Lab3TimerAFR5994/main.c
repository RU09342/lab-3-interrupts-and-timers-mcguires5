#include <msp430.h> 


unsigned int count = 0;
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= (BIT0 + BIT1);
    P1OUT &= 0x00; // Set the LEDs off

                        // CCR0 interrupt enabled

    TB0CCTL0 = CCIE;   // CCR0 interrupt enabled
    TBCTL = TBSSEL_2 + MC_1 + ID_3; // SMCLK/8, UPMODE

    TBCCR0 = 0xFFFF; // CCR0 = 65535 is the number that the clock counts to
    //1250000/8 = 156250
    //65535/156250 = 0.4 so the led toggles every 0.4 seconds
    __enable_interrupt();

    __bis_SR_register(LPM0 + GIE); // LPM0 with interrupts enabled
    __enable_interrupt();

    __bis_SR_register(LPM0 + GIE); // LPM0 with interrupts enabled


}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0 (void)
{

    P1OUT ^= (BIT0 + BIT1); // Toggles LEDS

}