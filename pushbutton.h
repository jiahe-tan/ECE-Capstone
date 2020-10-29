#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <msp430.h>

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                 OnOffbutton
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   GPIO      :  P1.3
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define DAYNIGHTBUTTON_BIT						BIT3	// Port pin bit location for pushbutton
#define DAYNIGHTBUTTON_REN  					P1REN   // Register to enable resistors for pushbutton
#define DAYNIGHTBUTTON_PORT						P1IN 	// Register to select pull-up/pull-down
#define DAYNIGHTBUTTON_DDR						P1DIR 	// Data Direction Register (DDR) for pushbutton.
#define SET_DAYNIGHTBUTTON_TO_AN_INPUT			DAYNIGHTBUTTON_DDR &= ~DAYNIGHTBUTTON_BIT
#define ENABLE_PULL_UP_PULL_DOWN_RESISTORS_DAYNIGHT    DAYNIGHTBUTTON_REN |= DAYNIGHTBUTTON_BIT
#define SELECT_PULL_UP_RESISTORS_DAYNIGHT			    DAYNIGHTBUTTON_PORT |= DAYNIGHTBUTTON_BIT

#define AUTOBUTTON_BIT						BIT3	// Port pin bit location for pushbutton
#define AUTOBUTTON_REN  					P1REN   // Register to enable resistors for pushbutton
#define AUTOBUTTON_PORT						P1IN 	// Register to select pull-up/pull-down
#define AUTOBUTTON_DDR						P1DIR 	// Data Direction Register (DDR) for pushbutton.
#define SET_AUTOBUTTON_TO_AN_INPUT			AUTOBUTTON_DDR &= ~AUTOBUTTON_BIT
#define ENABLE_PULL_UP_PULL_DOWN_RESISTORS_AUTO	    AUTOBUTTON_REN |= AUTOBUTTON_BIT
#define SELECT_PULL_UP_RESISTORS_AUTO			    AUTOBUTTON_PORT |= AUTOBUTTON_BIT

// Prototypes
void InitializeDayNightButtonPortPin(void);
void InitializeAutoButtonPortPin(void);

int CheckButton(void);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                 Autobutton
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   GPIO      :  P1.3
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#endif
