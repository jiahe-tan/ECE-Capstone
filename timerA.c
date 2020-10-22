#include "timerA.h"

extern FSMType PWM;

void ConfigureTimerA(void)
{
	// Stop the timer and clear it.
	TA0CTL = ( MC_0 | TACLR);

    // PWM_PERIOD = TACCR0 + 1 => TACCR0 = PWM_PERIOD - 1 (see pwm.h)
    TA0CCR0 = PWM_PERIOD-1;
    TA0CCR1 = 0;

    TA0CTL |= TAIE;     // Enable Timer A Interrupt Flag (TAIFG)
    TA0CCTL0 |= CCIE;   // Enable TACCR0 Compare/Capture Interrupt Flag (CCIFG0)
    TA0CCTL1 |= CCIE;   // Enable TACCR1 Compare/Capture Interrupt Flag (CCIFG1)

    // Finally, start the timer in up mode, using SMCLK with the appropriate clock divide.
    TA0CTL |= (TASSEL_2 | TIMERA_CLOCK_DIVIDE | MC_1);
}

#pragma vector = TIMER0_A0_VECTOR
// Interrupt service routine for CCIFG0
__interrupt void Timer0A0ISR(void)
{
    NextStateFunction(&PWM);
}

#pragma vector = TIMER0_A1_VECTOR
// Interrupt service routine for CCIFG1 and TAIFG
__interrupt void Timer0A1ISR(void)
{
    OutputFunction(&PWM);
}
