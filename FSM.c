# include "FSM.h"
#include "LED.h"


enum states {S_ON, S_NMANUAL, S_DMANUAL, S_AUTO};
enum events {E_NON, E_NOFF, E_AUTOON, E_INC, E_DEC, E_TIMEOUT, E_MAX};

int	CurState= S_OFF;

void InitializeFSM(FSMType *FSM, char * FSMPort, unsigned char FSMBit)
{
    FSM->Direction = up;
    FSM->TA0CCR1Delta = TA0CCR1_DELTA;
    FSM->PWMPort = FSMPort;
    FSM->PWMPortBit = FSMBit;
}


void NextStateFunction(int event)
{
    int NextState = CurState;

    switch ( CurState )	
    {	
    case S_ON:
    	switch (event)
        {
		case E_NON:
		    NextState = S_NMANUAL;
		    break;
		case E_NOFF:
		    NextState = S_DMANUAL;
		    break;
        }
        break;

    case S_NMANUAL:	
    	switch (event)
        {
		
		case E_INC:
		    NextState = CurState;
		    break;
		case E_DEC:
		    NextState = CurState;
		    break;
        }
        break;

    case S_DMANUAL:	
    	switch (event)
        {
		case E_AUTOON:
		    NextState = S_AUTO;
		    break;
		case E_INC:
		    NextState = CurState;
		    break;
		case E_DEC:
		    NextState = CurState;
		    break;
        }
        break;

     case S_AUTO:	
        switch (event)
        {
		case E_AUTOOFF:
		    NextState = S_DMANUAL;
		    break;
        }
        break;

    default:
        break;

    }
    if (NextState != CurState)
    {
        OutputFunction(NextState);
        CurState = NextState;
    } 


}

void OutputFunction(int state)
{
        switch (state) {
        case S_OFF:
            break;
        case S_ON:
            break;
        case S_AUTO:
            break;
        case S_DMANUAL:
            break;
        case S_NMANUAL:
            break;
        }

}
