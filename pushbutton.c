#include "pushbutton.h"
#include "FSM.h"

extern FSMType PWM;

void InitializePushButtonPortPin (void)
{
	// Configure port pin for pushbutton
	ENABLE_PULL_UP_PULL_DOWN_RESISTORS;
	SELECT_PULL_UP_RESISTORS;
	SET_PUSHBUTTON_TO_AN_INPUT;
	ENABLE_PUSHBUTTON_INTERRUPT;
}

#pragma vector = PORT1_VECTOR
__interrupt void PushButtonISR(void)
{
    // Code to halt PWM and resume PWM.
    if (PWM.TA0CCR1Delta == 1){
        PWM.TA0CCR1Delta = 0;
    }
    else if (PWM.TA0CCR1Delta != 1){
        PWM.TA0CCR1Delta = 1;
    }
    CLEAR_PUSHBUTTON_INTERRUPT_FLAG;
}
