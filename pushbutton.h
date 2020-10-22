#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <msp430.h>

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                 OnOffbutton
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   GPIO      :  P1.3
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define ONOFFBUTTON_BIT						BIT3	// Port pin bit location for pushbutton
#define ONOFFBUTTON_REN  					P1REN   // Register to enable resistors for pushbutton
#define ONOFFBUTTON_PORT						P1OUT 	// Register to select pull-up/pull-down
#define ONOFFBUTTON_DDR						P1DIR 	// Data Direction Register (DDR) for pushbutton.
#define ONOFFBUTTON_IE   					P1IE    // Port interrupt enable
#define ONOFFBUTTON_IFG  					P1IFG   // Port interrup flag
#define SET_ONOFFBUTTON_TO_AN_INPUT			PUSHBUTTOONOFFR &= ~ONOFFBUTTON_BIT
#define ENABLE_PULL_UP_PULL_DOWN_RESISTORS	ONOFFBUTTON_REN |= ONOFFBUTTON_BIT
#define SELECT_PULL_UP_RESISTORS			ONOFFBUTTON_PORT |= ONOFFBUTTON_BIT
#define ENABLE_ONOFFBUTTON_INTERRUPT			ONOFFBUTTON_IE |= ONOFFBUTTON_BIT
#define CLEAR_ONOFFBUTTON_INTERRUPT_FLAG		ONOFFBUTTON_IFG &= ~ONOFFBUTTON_BIT

// Prototypes
void InitializePushButtonPortPin(void);


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                 Autobutton
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   GPIO      :  P1.3
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#endif
