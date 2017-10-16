#include <msp430.h>


/**
 * main.c
 */

//TIMER
unsigned int initialTime = 0;
unsigned int OverFlowTimes = 0;
unsigned int NumOfOverFlow = 0;
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    P1DIR |= (BIT0 + BIT6);
    P1OUT &= 0x00; // Set the LEDs off
                   // CCR0 interrupt enabled
    TB0CTL = TBSSEL_2 + MC_1 + ID_3;           // SMCLK/8, upmode
    TB0CCTL0 = CCIE;
    TB0CCR0 =  0xFFFF;  //Number timer counts to
    P1DIR |= (BIT0);
    P2DIR |= (BIT0);
    P2OUT |= (BIT0);
    P1IE |= (BIT1);       //Enables interrupts for P1 Bit 1
    P1IES |= BIT1;
    P1REN |= (BIT1);    //Enables the resistor for P1 Bit 1
    P1OUT |= (0x03);
    P1OUT |= (BIT1);//Sets the resistor for P1 Bit 1 to Pull Up
    P1IFG &= ~(BIT1);   //The interrupt flag is cleared


    //enable all interrupts
    __bis_SR_register(GIE); // LPM0 with interrupts enabled

}


// Timer A0 interrupt service routine
#pragma vector=TIMER0_B0_VECTOR
__interrupt void TIMER0_B0_ISR (void)
{
     P2OUT ^= BIT0;              // Toggle P1.0
}


//Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    if(P1IES == BIT1){
        TB0R = 0;
        initialTime = TB0R;
        P1OUT |= BIT0;
    }else{
        P1OUT &= ~BIT0;
        TB0CCR0 = TB0R - initialTime;
    }
    //Simple Debounce
    __delay_cycles(1000);
    P1IES ^= BIT1;
    P1IFG &= ~BIT1;

}
