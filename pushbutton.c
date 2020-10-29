#include "pushbutton.h"
#include "FSM.h"

extern FSMType PWM;

void InitializeDayNightButtonPortPin (void)
{
	// Configure port pin for pushbutton
	ENABLE_PULL_UP_PULL_DOWN_RESISTORS_DAYNIGHT;
	SELECT_PULL_UP_RESISTORS_DAYNIGHT;
	SET_DAYNIGHTBUTTON_TO_AN_INPUT;
	ENABLE_DAYNIGHTBUTTON_INTERRUPT;
}

void InitializeAutoButtonPortPin (void)
{
	// Configure port pin for pushbutton
	ENABLE_PULL_UP_PULL_DOWN_RESISTORS_AUTO;
	SELECT_PULL_UP_RESISTORS_AUTO;
	SET_AUTOBUTTON_TO_AN_INPUT;
	ENABLE_AUTOBUTTON_INTERRUPT;
}


int CheckButtons()
{

	if(~DAYNIGHTBUTTON_PORT & DAYNIGHTBUTTON_BIT)	
	{
		if (Current_State == S_ON)
			{
			return S_NMANUAL;
			}
		else
			{
			return S_DMANUAL;
			}
	}

	if(~AUTOBUTTON_PORT	 & AUTOBUTTON_BIT)	
	{
		if (Current_State == S_DMANUAL)	
			{
			return S_AUTO;
			}
		else if (Current_State == S_AUTO)
			{
			return S_DMANUAL;
			}
		else
			{
			return Current_State;
			}
	}

}
