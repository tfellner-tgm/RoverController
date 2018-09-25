/* ***************************************************
 * Model File: Model::Impelementation::RoverController::FSM::FSM
 * Model Path: C:\Users\Thomas\source\repos\RoverController2\RoverControllerModel.eap
 * 
 * 2018-09-25  - 16:12
 * ***************************************************
 *  */
#include "FSM.h"

/* Operation 'checkTimeEvent' of class 'FSM' */
bool FSM_checkTimeEvent(FSM_STATE* state, long value, time_units unit)
{
    /* SyncableUserCode{34922A71-8EF6-4504-B158-878BF04A27BF}:1GlF7Zgm02 */
    uint64_t difference;
    uint64_t valueToCheck;
    bool timePassed = false;

    difference = (FSM_getTime() - state->startTime);

    switch (unit)
    {
    case TIME_NANOSECONDS:
        valueToCheck = value / 1000000UL;
        break;
    case TIME_MICROSECONDS:
        valueToCheck = value / 1000UL;
        break;
    case TIME_TICKS:
        valueToCheck = value;
        break;
    case TIME_MILLISECONDS:
        valueToCheck = value;
        break;
    case TIME_SECONDS:
        valueToCheck = value * 1000UL;
        break;
    case TIME_MINUTES:
        valueToCheck = value * 1000UL * 60UL;
        break;
    case TIME_HOURS:
        valueToCheck = value * 1000UL * 60UL * 60UL;
        break;
    default:
        difference = 0UL;
        valueToCheck = 1UL;
        break;
    }

    if (difference >= valueToCheck)
    {
        timePassed = true;
    }

    return timePassed;
    /* SyncableUserCode{34922A71-8EF6-4504-B158-878BF04A27BF} */
}

/* Operation 'getTime' of class 'FSM' */
long FSM_getTime(void)
{
    /* SyncableUserCode{7225191D-3EC2-4fcc-B53D-8E880AABA3B7}:1RZy1gyPAU */
    /* TODO: Provide an implementation to get the correct time */
    return clock();
    /* SyncableUserCode{7225191D-3EC2-4fcc-B53D-8E880AABA3B7} */
}

