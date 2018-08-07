/* ***************************************************
 * Model File: Model::Impelementation::RoverController::RoverController
 * Model Path: C:\Users\Thomas\source\repos\StaticLibrary\RoverControllerModel.eap
 * 
 * 2018-08-07  - 17:46
 * ***************************************************
 *  */
#include "RoverController.h"

/* Statically allocated instance. Automatically added and generated. */
RoverController RoverController_me;

/* Returns a pointer to the statically allocated structure for RoverController.
 * Automatically added and generated.
 * @return Pointer to the statically allocated structure for RoverController. */
RoverController* RoverController_new(void)
{
    return &RoverController_me;
}

/* Activity DistanceHandler of class RoverController */
void RoverController_DistanceHandler(RoverController* const me)
{
    double distance;
    /* start of activity code */
    /* Setup for loop */
    /* SyncableUserCode{AC11ED8D-898E-4a1f-AE8E-7631B0FD91E8}:1Onip9RC6L */
    int i = 0;
    /* SyncableUserCode{AC11ED8D-898E-4a1f-AE8E-7631B0FD91E8} */

    do
    {
        /* SyncableUserCode{D32071E0-AF43-44df-A06B-F7371E40289C}:PZHteyRNjj */
        distance = getFirstParam(getLeaderDistance());
        /* SyncableUserCode{D32071E0-AF43-44df-A06B-F7371E40289C} */

        if (distance >= 12.5)
        {
            /* SyncableUserCode{3AE64D02-CF15-4a15-A1D2-B80342BCAB1D}:Z0oOaPsCNL */
            int speed = (distance - 12.5) * 47.5 + 5;
            if (speed > 100)
            {
                speed = 100;
            }
            /* SyncableUserCode{3AE64D02-CF15-4a15-A1D2-B80342BCAB1D} */

            /* SyncableUserCode{97F5C2F7-F60C-44d4-A358-EC4CB5B1CF69}:wzHY7aKkSb */
            setLRPower(speed, speed);
            /* SyncableUserCode{97F5C2F7-F60C-44d4-A358-EC4CB5B1CF69} */
        }
        else if (distance < 12.5)
        {
            /* SyncableUserCode{9D0866F8-ACDF-4842-911A-2184AC4655B9}:1TZC6m80BG */
            setLRPower(0, 0);
            /* SyncableUserCode{9D0866F8-ACDF-4842-911A-2184AC4655B9} */
        }
        else
        {
        }
        /* SyncableUserCode{12B56C32-674D-48f5-93E8-29CAECA988A5}:fSOJnDkv0w */
        Sleep(150);
        /* SyncableUserCode{12B56C32-674D-48f5-93E8-29CAECA988A5} */

        /* SyncableUserCode{0DEBF4E0-A1D6-4c0e-81CD-1A75B7AA9473}:bfu5YXWBGJ */
        i++;
        /* SyncableUserCode{0DEBF4E0-A1D6-4c0e-81CD-1A75B7AA9473} */

    } while (i < 400);

    return;
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
        /* SyncableUserCode{882A85FD-23BB-40a9-9BB9-409454FA7DE9}:1UHWRoTU3q */
        char* leaderGPS = getLeaderGPS();
        double leaderX = getFirstParam(leaderGPS);
        double leaderY = getSecondParam(leaderGPS);

        char* roverGPS = getRoverGPS();
        double roverX = getFirstParam(roverGPS);
        double roverY = getSecondParam(roverGPS);

        printf("LX: %f, LY: %f, RX: %f, RY: %f \n", leaderX, leaderY, roverX, roverY);
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
        /* SyncableUserCode{BA029F47-0CC5-4459-B666-C925810EC15F}:8ULXkxBnt9 */
        Sleep(300);
        /* SyncableUserCode{BA029F47-0CC5-4459-B666-C925810EC15F} */

        /* SyncableUserCode{5B6C3A39-85D8-47bc-B039-54765D18301B}:bfu5YXWBGJ */
        i++;
        /* SyncableUserCode{5B6C3A39-85D8-47bc-B039-54765D18301B} */

    } while (i < 200);

    return;
}

