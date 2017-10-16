#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= (BIT0);
    P5IE |= (BIT6);       //Enables interrupts for P1 Bit 1
    P5IES |= BIT6;
    P5REN |= (BIT6);    //Enables the resistor for P1 Bit 1
    P5OUT |= (BIT6);    //Sets the resistor for P1 Bit 1 to Pull Up
    //P1GIE |= (BIT1);    //Enables general interrupts
    P5IFG &= ~(BIT6);   //The interrupt flag is cleared

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings


       //enable all interrupts
    __bis_SR_register(LPM0_bits + GIE);       // Enter LPM4 w/interrupt
}
//Port 1 interrupt service routine
#pragma vector=PORT5_VECTOR
__interrupt void Port_5(void)
{
    P1OUT ^= BIT0;
    P5IFG &= ~BIT6;

}

