/* ***************************************************
 * Model File: Model::Impelementation::RoverController::FSM::FSM
 * Model Path: C:\Users\Thomas\source\repos\RoverController2\RoverControllerModel.eap
 * 
 * 2018-09-25  - 16:12
 * ***************************************************
 *  */
#ifndef H_FSM
#define H_FSM

#include "FSM_STATE.h" /* Include for 'relation to classifier' 'FSM_STATE' */
#include <time.h>/* Include for 'relation to classifier' 'time' */
#include "MissingTypes.h" /* Include for 'relation to classifier' 'MissingTypes' */
#include "time_units.h" /* Include for 'relation to classifier' 'time_units' */

/* Operation 'checkTimeEvent' of class 'FSM' */
bool FSM_checkTimeEvent(FSM_STATE* state, long value, time_units unit);

/* Operation 'getTime' of class 'FSM' */
long FSM_getTime(void);

#endif /* #ifndef H_FSM */

