#ifndef PWM_H_
#define PWM_H_

#define TA0CCR1_DELTA 1
#define CALDCO_FREQUENCY CALDCO_1MHZ
#define CALBC1_FREQUENCY CALBC1_1MHZ
#define SMCLK_DIVIDE DIVS_3
#define TIMERA_CLOCK_DIVIDE ID_3
#define PWM_PERIOD 65500 // Equals (SMCLK_FREQUENCY/DUTY_CYCLE_FREQUENCY)/TIMERA_CLOCK_DIVIDE

#endif /* PWM_H_ */
