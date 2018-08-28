/* ***************************************************
 * Model File: Model::Impelementation::RoverController::RoverController
 * Model Path: C:\Users\Thomas\source\repos\RoverController\RoverControllerModel.eap
 * 
 * 2018-08-28  - 20:43
 * ***************************************************
 *  */
#ifndef H_ROVERCONTROLLER
#define H_ROVERCONTROLLER

#include "MissingTypes.h" /* Include for 'relation to classifier' 'MissingTypes' */
#include "FSM.h" /* Include for 'relation to classifier' 'FSM' */
#include "roverCommunicationLib.h" /* Include for 'relation to classifier' 'roverCommunicationLib' */
#include "Signals.h" /* Include for 'relation to classifier' 'Signals' */
#include <stdio.h>/* Include for 'relation to classifier' 'stdio' */
#include <math.h>/* Include for 'relation to classifier' 'math' */
#include <time.h>/* Include for 'relation to classifier' 'time' */
#include <Windows.h>/* Include for 'relation to classifier' 'Windows' */

/* Enumeration defining all states of state machine DistanceHandler */
typedef enum {
    RoverController_DistanceHandler_NOSTATE = 0, /* Explicit value specification added by code generator */
    RoverController_DistanceHandler_Calculate_Bounds,
    RoverController_DistanceHandler_Calculate_Distance,
    RoverController_DistanceHandler_DistanceHandler_FINAL_1,
    RoverController_DistanceHandler_Increment,
    RoverController_DistanceHandler_Mid_Range,
    RoverController_DistanceHandler_Set_Speed,
    RoverController_DistanceHandler_Too_close,
    RoverController_DistanceHandler_Too_Far
} RoverController_DistanceHandler_States;

typedef struct RoverController_DistanceHandler_STMStruct
{
    FSM_STATE mainState; /* State variable for the state machine */
    FSM_STATE Calculate_Bounds; /* State variable for state Calculate Bounds */
    FSM_STATE Calculate_Distance; /* State variable for state Calculate Distance */
    FSM_STATE Increment; /* State variable for state Increment */
    FSM_STATE Mid_Range; /* State variable for state Mid Range */
    FSM_STATE Set_Speed; /* State variable for state Set Speed */
    FSM_STATE Too_close; /* State variable for state Too close */
    FSM_STATE Too_Far; /* State variable for state Too Far */
} RoverController_DistanceHandler_STM;

typedef struct RoverControllerStruct
{
    RoverController_DistanceHandler_STM DistanceHandler;
} RoverController;

/* Returns a pointer to the statically allocated structure for RoverController.
 * Automatically added and generated.
 * @return Pointer to the statically allocated structure for RoverController. */
RoverController* RoverController_new(void);

/* Activity AngleHandler of class RoverController */
void RoverController_AngleHandler(RoverController* const me);

/* Handles the state machine */
bool RoverController_DistanceHandler(RoverController* const me, RoverController_DistanceHandler_STM* stm, /*  Pointer to the current state machine instance */
                                     Signals msg /*  Signal for the state machine */
                                     );

/* Initialization code for this state machine */
void RoverController_DistanceHandler_init(RoverController* const me, RoverController_DistanceHandler_STM* const stm);

#endif /* #ifndef H_ROVERCONTROLLER */

