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
    TA0CTL = TASSEL_2 + MC_1 + ID_3;           // SMCLK/8, upmode
    TA0CCTL0 = CCIE;
    TA0CCR0 =  0xFFFF;  //Number timer counts to
    P1DIR |= (BIT0);
    P1DIR |= (BIT6);
    P1OUT |= (BIT6);
    P1IE |= (BIT3);       //Enables interrupts for P1 Bit 1
    P1IES |= BIT3;
    P1REN |= (BIT3);    //Enables the resistor for P1 Bit 1
    P1OUT |= (BIT3);
    P1OUT |= (BIT3);//Sets the resistor for P1 Bit 1 to Pull Up
    P1IFG &= ~(BIT3);   //The interrupt flag is cleared


    //enable all interrupts
    __bis_SR_register(GIE); // LPM0 with interrupts enabled

}


// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR (void)
{
     P1OUT ^= BIT6;              // Toggle P1.0
}


//Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    if(P1IES == BIT3){
        TA0R = 0;
        initialTime = TA0R;
        P1OUT |= BIT0;
    }else{
        P1OUT &= ~BIT0;
        TA0CCR0 = TA0R - initialTime;
    }
    //Simple Debounce
    __delay_cycles(1000);
    P1IES ^= BIT3;
    P1IFG &= ~BIT3;

}
