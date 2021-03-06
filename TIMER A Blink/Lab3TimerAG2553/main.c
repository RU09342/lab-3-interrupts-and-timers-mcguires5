#include <msp430.h> 



unsigned int count = 0;
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    P1DIR |= (BIT0 + BIT6);
    P1OUT &= 0x00; // Set the LEDs off

                        // CCR0 interrupt enabled

    CCTL0 = CCIE;
    TACTL = TASSEL_2 + MC_1 + ID_3; // SMCLK/8, UPMODE


    TACCR0 = 0xFFFF; // CCR0 = 65535 is the number that the clock counts to
    //1250000/8 = 156250
    //65535/156250 = 0.4 so the led toggles every 0.4 seconds
    __enable_interrupt();

    __bis_SR_register(LPM0 + GIE); // LPM0 with interrupts enabled


}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0 (void)
{

    P1OUT ^= (BIT0 + BIT6); // Toggles LEDS

}
