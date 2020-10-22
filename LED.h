#ifndef LED_H
#define LED_H

#include <msp430.h>

//  Green LED
#define LED 1
#define LED_BIT				BIT2
#define LED_PORT				P2OUT
#define LED_DDR				P2DIR
#define SET_LED_AS_AN_OUTPUT	ED_DDR |= LED_BIT
#define TURN_ON_LED		    LED_PORT |= ED_BIT
#define TURN_OFF_LED		    LED_PORT &= ~LED_BIT

// Prototypes
void InitializeLEDPortPins(void);

#endif
