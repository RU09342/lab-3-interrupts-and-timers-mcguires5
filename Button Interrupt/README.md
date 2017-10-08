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

### Energy Trace Analysis
I have run the energy trace software inside code composer and have found that in active mode, when the processor and all timers are enabled it consumed an average of __ uW.
In LPM0 - __ uW
In LPM1 - __ uW
In LPM2 - __ uW
In LPM3 - __ uW