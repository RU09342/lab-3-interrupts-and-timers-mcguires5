#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= (BIT0);
    P1IE |= (BIT3);       //Enables interrupts for P1 Bit 1
    P1IES |= BIT3;
    P1REN |= (BIT3);    //Enables the resistor for P1 Bit 1
    P1OUT |= (BIT3);    //Sets the resistor for P1 Bit 1 to Pull Up
    //P1GIE |= (BIT1);    //Enables general interrupts
    P1IFG &= ~(BIT3);   //The interrupt flag is cleared



       //enable all interrupts
    __bis_SR_register(LPM0_bits + GIE);       // Enter LPM4 w/interrupt
}
//Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    P1OUT ^= BIT0;
    P1IFG &= ~BIT3;

}

