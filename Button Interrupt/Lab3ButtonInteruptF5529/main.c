#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= (BIT0);
    P2IE |= (BIT1);       //Enables interrupts for P1 Bit 1
    P2IES |= BIT1;
    P2REN |= (BIT1);    //Enables the resistor for P1 Bit 1
    P2OUT |= (0x03);    //Sets the resistor for P1 Bit 1 to Pull Up
    //P1GIE |= (BIT1);    //Enables general interrupts
    P2IFG &= ~(BIT1);   //The interrupt flag is cleared

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings


       //enable all interrupts
    __bis_SR_register(LPM0_bits + GIE);       // Enter LPM4 w/interrupt
}
//Port 1 interrupt service routine
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
    P1OUT ^= BIT0;
    P2IFG &= ~BIT1;

}

