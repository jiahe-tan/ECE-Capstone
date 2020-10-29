#ifndef FSM_H_
#define FSM_H_

#include <msp430.h>
#include "pwm.h"

typedef struct {
    unsigned char TA0CCR1Delta; // Increment for TA0CCR1
    enum {up, down} Direction;  // Indicates "direction" of modulation
    char * PWMPort;             // Port register used for PWM
    unsigned char PWMPortBit;   // Bit mask that corresponds to port pin used for PWM
} FSMType;

// Function Prototypes
void InitializeFSM(FSMType *FSM, char * FSMPort, unsigned char FSMBit);
void NextStateFunction(FSMType *FSM);
void OutputFunction(FSMType *FSM);

#endif /* FSM_H_ */