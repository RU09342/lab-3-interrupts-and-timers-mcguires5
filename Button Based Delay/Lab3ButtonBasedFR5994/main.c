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
    P1DIR |= (BIT1);
    P1OUT |= (BIT1);
    P5IE |= (BIT6);       //Enables interrupts for P1 Bit 1
    P5IES |= BIT6;
    P5REN |= (BIT6);    //Enables the resistor for P1 Bit 1
    P5OUT |= (BIT6);
    P5OUT |= (BIT6);//Sets the resistor for P1 Bit 1 to Pull Up
    P5IFG &= ~(BIT6);   //The interrupt flag is cleared


    //enable all interrupts
    __bis_SR_register(GIE); // LPM0 with interrupts enabled

}


// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR (void)
{
     P1OUT ^= BIT1;              // Toggle P1.0
}


//Port 1 interrupt service routine
#pragma vector=PORT5_VECTOR
__interrupt void Port_5(void)
{
    if(P5IES == BIT6){
        TA0R = 0;
        initialTime = TA0R;
        P1OUT |= BIT0;
    }else{
        P1OUT &= ~BIT0;
        TA0CCR0 = TA0R - initialTime;
    }
    //Simple Debounce
    __delay_cycles(1000);
    P5IES ^= BIT6;
    P5IFG &= ~BIT6;

}
