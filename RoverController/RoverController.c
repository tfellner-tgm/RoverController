/* ***************************************************
 * Model File: Model::Impelementation::RoverController::RoverController
 * Model Path: C:\Users\Thomas\source\repos\RoverController\RoverControllerModel.eap
 * 
 * 2018-08-28  - 20:43
 * ***************************************************
 *  */
#include "RoverController.h"

static int i;

static double speed = 0.0;

static int distance = 0.0;

/* Statically allocated instance. Automatically added and generated. */
RoverController RoverController_me;

/* Returns a pointer to the statically allocated structure for RoverController.
 * Automatically added and generated.
 * @return Pointer to the statically allocated structure for RoverController. */
RoverController* RoverController_new(void)
{
    return &RoverController_me;
}

/* Activity AngleHandler of class RoverController */
void RoverController_AngleHandler(RoverController* const me)
{
    double deltaAngle;
    double deltaX;
    double deltaY;
    /* start of activity code */
    /* Setup for loop */
    /* SyncableUserCode{F1AACFA9-1394-4892-BAD6-67E4E66FE584}:1Onip9RC6L */
    int i = 0;
    /* SyncableUserCode{F1AACFA9-1394-4892-BAD6-67E4E66FE584} */

    do
    {
        /* SyncableUserCode{882A85FD-23BB-40a9-9BB9-409454FA7DE9}:1bnvPDe7YN */
        char* leaderGPS = getLeaderGPS();
        double leaderX = getFirstParam(leaderGPS);
        double leaderY = getSecondParam(leaderGPS);

        char* roverGPS = getRoverGPS();
        double roverX = getFirstParam(roverGPS);
        double roverY = getSecondParam(roverGPS);
        /* SyncableUserCode{882A85FD-23BB-40a9-9BB9-409454FA7DE9} */

        /* SyncableUserCode{8653EBFB-4B86-4620-AF1C-1219AD3255B4}:mgEB7D869X */
        deltaX = leaderX - roverX;
        deltaY = leaderY - roverY;
        /* SyncableUserCode{8653EBFB-4B86-4620-AF1C-1219AD3255B4} */

        /* SyncableUserCode{121B8AD1-A38E-46cf-A0C5-7F7D9371D728}:I78LBLptxu */
        double leaderAngle = atan(deltaX / deltaY) * 180 / 3.14159265358979323846;
        double roverAngle = getFirstParam(getRoverCompass());

        if (roverAngle > 180)
        {
            roverAngle -= 360;
        }

        deltaAngle = leaderAngle - roverAngle;
        /* SyncableUserCode{121B8AD1-A38E-46cf-A0C5-7F7D9371D728} */

        if (deltaAngle > 1)
        {
            /* SyncableUserCode{D5462A53-433C-41a6-A6E0-D231A8971BE8}:rNfqljY4eX */
            setLRPower(50, -50);
            /* SyncableUserCode{D5462A53-433C-41a6-A6E0-D231A8971BE8} */
        }
        else if (deltaAngle < -1)
        {
            /* SyncableUserCode{08FE74EA-B8A1-449b-86C5-423E05D72071}:iKAsUKGnxu */
            setLRPower(-50, 50);
            /* SyncableUserCode{08FE74EA-B8A1-449b-86C5-423E05D72071} */
        }
        else
        {
        }
        /* SyncableUserCode{BA029F47-0CC5-4459-B666-C925810EC15F}:kzKcnX40ja */
        Sleep(200);
        /* SyncableUserCode{BA029F47-0CC5-4459-B666-C925810EC15F} */

        /* SyncableUserCode{5B6C3A39-85D8-47bc-B039-54765D18301B}:bfu5YXWBGJ */
        i++;
        /* SyncableUserCode{5B6C3A39-85D8-47bc-B039-54765D18301B} */

    } while (i < 300);

    return;
}

/* Handles the state machine */
bool RoverController_DistanceHandler(RoverController* const me, RoverController_DistanceHandler_STM* stm, /*  Pointer to the current state machine instance */
                                     Signals msg /*  Signal for the state machine */
                                     )
{
    bool evConsumed = !1; /* Indicates if the event has already been consumed */
    switch (stm->mainState.activeSubState)
    {
    case RoverController_DistanceHandler_Calculate_Bounds:

        evConsumed = !0;
        /* From 'Calculate Bounds' to 'Set Speed' */
        stm->mainState.activeSubState = RoverController_DistanceHandler_Set_Speed;
        /* User-supplied code: Operation 'setSpeed', {E8C20C37-0F1D-4831-9E53-2B10C62A6D12} */
        setLRPower((int)speed, (int)speed);
        /* end of entry actions for state Set Speed */

        break;
    case RoverController_DistanceHandler_Calculate_Distance:

        /* From 'Calculate Distance' to 'Distance?' */

        if (distance < 12.7)
        {
            evConsumed = !0;
            /* From 'Distance?' to 'Too close' */
            stm->mainState.activeSubState = RoverController_DistanceHandler_Too_close;
            /* User-supplied code: Operation 'distanceZero', {1174C801-C1AA-4291-98F3-B79EA2B56007} */
            speed = 0.0;
            /* end of entry actions for state Too close */
        }
        else if (distance >= 12.7 && distance < 13.5)
        {
            evConsumed = !0;
            /* From 'Distance?' to 'Mid Range' */
            stm->mainState.activeSubState = RoverController_DistanceHandler_Mid_Range;
            /* User-supplied code: Operation 'quadraticEquation', {4F6863D2-AD6D-4715-AE82-8FDA022B707A} */
            // quadratic equation
            speed = 15 * (distance * distance) - 360 * distance + 2160;
            /* end of entry actions for state Mid Range */
        }
        else
        {
            evConsumed = !0;
            /* From 'Distance?' to 'Too Far' */
            stm->mainState.activeSubState = RoverController_DistanceHandler_Too_Far;
            /* User-supplied code: Operation 'logisticalGrowth', {7C30788F-C8B2-4006-BA27-1CA60B3DF722} */
            // logistical growth
            speed = 1 + (10 * 100) / (10 + (100 - 10) * exp(-(100 * 0.045 * (distance - 12.7))));
            /* end of entry actions for state Too Far */
        }

        break;
    case RoverController_DistanceHandler_DistanceHandler_FINAL_1:
        break;
    case RoverController_DistanceHandler_Increment:

        if (FSM_checkTimeEvent(&(stm->Increment), 150, TIME_MILLISECONDS) != !1)
        {
            /* From 'Increment' to 'Check Increment' */

            if (i < 400)
            {
                evConsumed = !0;
                /* From 'Check Increment' to 'Calculate Distance' */
                stm->mainState.activeSubState = RoverController_DistanceHandler_Calculate_Distance;
                /* User-supplied code: Operation 'calculateDistance', {2EEBCD1C-A2AB-4f5c-9120-ABEC59F92280} */
                distance = getFirstParam(getLeaderDistance());

                if (i < 2)
                {
                    distance = 14;
                }
                /* end of entry actions for state Calculate Distance */
            }
            else
            {
                evConsumed = !0;
                /* From 'Check Increment' to 'Final' */
                stm->mainState.activeSubState = RoverController_DistanceHandler_DistanceHandler_FINAL_1;
            }
        }
        break;
    case RoverController_DistanceHandler_Mid_Range:

        evConsumed = !0;
        /* From 'Mid Range' to 'Calculate Bounds' */
        stm->mainState.activeSubState = RoverController_DistanceHandler_Calculate_Bounds;
        /* User-supplied code: Operation 'calculateBounds', {1DB6B35A-1B85-4f60-93E2-696715DFEAB5} */
        if (speed > 100)
        {
            speed = 100;
        }
        else if (speed < 0)
        {
            speed = 0;
        }
        /* end of entry actions for state Calculate Bounds */

        break;
    case RoverController_DistanceHandler_Set_Speed:

        evConsumed = !0;
        /* From 'Set Speed' to 'Increment' */
        stm->mainState.activeSubState = RoverController_DistanceHandler_Increment;
        stm->Increment.startTime = FSM_getTime();
        /* User-supplied code: Operation 'increment', {0C99E8F6-7167-49bd-9FC6-01468FA3A150} */
        i++;
        /* end of entry actions for state Increment */

        break;
    case RoverController_DistanceHandler_Too_close:

        evConsumed = !0;
        /* From 'Too close' to 'Calculate Bounds' */
        stm->mainState.activeSubState = RoverController_DistanceHandler_Calculate_Bounds;
        /* User-supplied code: Operation 'calculateBounds', {1DB6B35A-1B85-4f60-93E2-696715DFEAB5} */
        if (speed > 100)
        {
            speed = 100;
        }
        else if (speed < 0)
        {
            speed = 0;
        }
        /* end of entry actions for state Calculate Bounds */

        break;
    case RoverController_DistanceHandler_Too_Far:

        evConsumed = !0;
        /* From 'Too Far' to 'Calculate Bounds' */
        stm->mainState.activeSubState = RoverController_DistanceHandler_Calculate_Bounds;
        /* User-supplied code: Operation 'calculateBounds', {1DB6B35A-1B85-4f60-93E2-696715DFEAB5} */
        if (speed > 100)
        {
            speed = 100;
        }
        else if (speed < 0)
        {
            speed = 0;
        }
        /* end of entry actions for state Calculate Bounds */

        break;
    default:
        break;
    }
    return evConsumed;
}

/* Initialization code for this state machine */
void RoverController_DistanceHandler_init(RoverController* const me, RoverController_DistanceHandler_STM* const stm)
{
    /* State: Calculate Bounds */
    stm->Calculate_Bounds.activeSubState = RoverController_DistanceHandler_NOSTATE;
    /* State: Calculate Distance */
    stm->Calculate_Distance.activeSubState = RoverController_DistanceHandler_NOSTATE;
    /* State: Increment */
    stm->Increment.activeSubState = RoverController_DistanceHandler_NOSTATE;
    /* State: Mid Range */
    stm->Mid_Range.activeSubState = RoverController_DistanceHandler_NOSTATE;
    /* State: Set Speed */
    stm->Set_Speed.activeSubState = RoverController_DistanceHandler_NOSTATE;
    /* State: Too close */
    stm->Too_close.activeSubState = RoverController_DistanceHandler_NOSTATE;
    /* State: Too Far */
    stm->Too_Far.activeSubState = RoverController_DistanceHandler_NOSTATE;

    /* From 'Initial' to 'Calculate Distance' */
    stm->mainState.activeSubState = RoverController_DistanceHandler_Calculate_Distance;
    /* User-supplied code: Operation 'calculateDistance', {2EEBCD1C-A2AB-4f5c-9120-ABEC59F92280} */
    distance = getFirstParam(getLeaderDistance());

    if (i < 2)
    {
        distance = 14;
    }
    /* end of entry actions for state Calculate Distance */
}

