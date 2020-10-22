#include <msp430.h>

#include "pwm.h"
#include "LED.h"
#include "pushbutton.h"
#include "timerA.h"
#include "FSM.h"

// Global variable
FSMType PWM;

// Function prototypes
void ConfigureClockModule(void);



void main(void)
{
	// Stop the watchdog timer, and configure the clock module.
	WDTCTL = WDTPW + WDTHOLD;
	ConfigureClockModule();

    // Initialize port pins and hardware.
    InitializeLEDPortPins();
    InitializePushButtonPortPin();
	ConfigureTimerA();

    // Initialize Finite State Machine (FSM).
    InitializeFSM(&PWM, (char *) &RED_LED_PORT, RED_LED_BIT);

    _enable_interrupts();
}

void ConfigureClockModule(void)
{
    // Configure Digitally Controlled Oscillator (DCO) using factory calibrations.
	DCOCTL  = CALDCO_FREQUENCY;
	BCSCTL1 = CALBC1_FREQUENCY;

	// Divide SMCLK
	BCSCTL2 |= SMCLK_DIVIDE;
}

