# Button Based Delay
For this assignment we will use a the duration of a button being held to set a timer which will controll an LED. The LED is initially blinked at a rate of 10 kHz before the button has been pressed.  

## Boards Implemented On:
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989
* MSP430G2553

## Differences On Boards
### MSP430F5529
P2.1 is used for the button. P1.0 is used to identify when the button is pressed down. P4.7 is used to show the the output of the TimerA module.

### MSP430FR2311
P1.1 is used for the button. P1.0 is used to identify when the button is pressed down. P2.0 is used to show the the output of the TimerB module.

### MSP430FR5994
P5.6 is used for the button. P1.0 is used to identify when the button is pressed down. P1.1 is used to show the the output of the TimerA module.

### MSP430FR6989
P1.1 is used for the button. P1.0 is used to identify when the button is pressed down. P9.7 is used to show the the output of the TimerB module.

### MSP430G2553
P1.3 is used for the button. P1.0 is used to identify when the button is pressed down. P1.6 is used to show the the output of the TimerA module.

