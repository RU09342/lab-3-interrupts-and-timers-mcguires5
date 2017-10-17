# Button Interrupt
This portion of the lab focuses on triggering an interupt using a button press.

'''c
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
}
'''

While you still need to initialize the Ports to be interrupt enabled and clear the flags, this "Pragma Vector" tells the compiler that when a particular interrupt occurs, run this code. 

An interupt is used to stop whatever process the processor is running and interject a section of the code (the interupt). To trigger an interupt with a button press one must enable interupts on the pin of the button using 
'''c
P1IE |= (BIT1);
'''
It is also good practice to clear the interupt flag on the pin using this line,
'''c
P1IFG |= (BIT1);
'''
I chose to trigger the interupt on the falling edge of the interupt, this is done using this line,
'''c
P1IES |= (BIT1);
'''
## Boards Implemented On:
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989
* MSP430G2553

## Differences On Boards
### MSP430F5529
P2.1 is used for the button. P1.0 is the LED used to identify when the button is pressed down. 

### MSP430FR2311
P1.1 is used for the button. P1.0 is the LED used to identify when the button is pressed down.

### MSP430FR5994
P5.6 is used for the button. P1.0 is the LED used to identify when the button is pressed down. 

### MSP430FR6989
P1.1 is used for the button. P1.0 is the LED used to identify when the button is pressed down.

### MSP430G2553
P1.3 is used for the button. P1.0 is the LED used to identify when the button is pressed down. 


### Energy Trace Analysis
I have run the energy trace software inside code composer and have found that in active mode, when the processor and all timers are enabled it consumed an average of __ uW.
In LPM0 - __ uW
In LPM1 - __ uW
In LPM2 - __ uW
In LPM3 - __ uW