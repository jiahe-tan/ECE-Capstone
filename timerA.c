#include "timerA.h"

extern FSMType PWM;

void ConfigureTimerA(void)
{
    // PWM_PERIOD = TACCR0 + 1 => TACCR0 = PWM_PERIOD - 1 (see pwm.h)
    TA0CCR0 = PWM_PERIOD-1;
    TA0CTL = TASSEL_2 + MC_1 + ID_3;     // Enable Timer A Interrupt Flag (TAIFG)
    TA0CCTL0 = CCIE;   // Enable TACCR0 Compare/Capture Interrupt Flag (CCIFG0)
    _BIS_SR( GIE );	
}

#pragma vector = TIMER0_A0_VECTOR
// Interrupt service routine for CCIFG0
__interrupt void Timer0A0ISR(void)
{
        sysTick = 1;
		LongDelay++;
		if(LongDelay >= 32)
		{LongDelay = 0;}
}

#pragma vector = TIMER0_A1_VECTOR
