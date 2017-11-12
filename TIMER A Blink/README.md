# TIMER A Blink
This lab focuses on blinking LED's at different rates using the timer module. This assignment will blink two LED's on the development boards. The LED's blink at a rate of one toggle every 0.4 seconds. This can be calculated from SMCLK / 8 /0xFFFF (CCR0 Value). This gives 0.4 seconds.

## Boards Implemented On:
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989
* MSP430G2553

## Differences On Boards
### MSP430F5529
P1.0 and P4.7 are the LEDS used. TimerB0 is used to trigger interupts.

### MSP430FR2311
P1.0 and P2.0 are the LED used. TimerB0 is used to trigger interupts.

### MSP430FR5994
P1.0 and P1.1 are the LEDS used. TimerA0 is used to trigger interupts.

### MSP430FR6989
P1.0 and P 9.7 are the LEDS used. TimerB0 is used to trigger interupts.

### MSP430G2553
P1.0 and P1.6 are the LEDS used. TimerA0 is used to trigger interupts.
