#ifndef TIMER_A_H
#define TIMER_A_H

#include <msp430.h>
#include "pwm.h"
#include "FSM.h"

volatile int	sysTick = 0;	// Volatile to prevent main code accessing a register copy
unsigned int	LongDelay = 0;	// Used to create a 15 Sec delay

// Prototypes
void ConfigureTimerA(void);

#endif
