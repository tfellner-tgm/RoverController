/* ***************************************************
 * Model File: Model::Impelementation::RoverController::RoverController
 * Model Path: C:\Users\Thomas\source\repos\StaticLibrary\RoverControllerModel.eap
 * 
 * 2018-08-08  - 13:38
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

/* Activity AngleHandler of class RoverController */
void RoverController_AngleHandler(RoverController* const me)
{
    /* start of activity code */
    /* Setup for loop */
    /* SyncableUserCode{F1AACFA9-1394-4892-BAD6-67E4E66FE584}:1Onip9RC6L */
    int i = 0;
    /* SyncableUserCode{F1AACFA9-1394-4892-BAD6-67E4E66FE584} */

    do
    {
        
        /* SyncableUserCode{BA029F47-0CC5-4459-B666-C925810EC15F}:kzKcnX40ja */
        Sleep(200);
        /* SyncableUserCode{BA029F47-0CC5-4459-B666-C925810EC15F} */

        /* SyncableUserCode{5B6C3A39-85D8-47bc-B039-54765D18301B}:bfu5YXWBGJ */
        i++;
        /* SyncableUserCode{5B6C3A39-85D8-47bc-B039-54765D18301B} */

    } while (i < 300);

    return;
}

/* Activity DistanceHandler of class RoverController */
void RoverController_DistanceHandler(RoverController* const me)
{
    double distance;
    /* start of activity code */
    /* Setup for loop */
    /* SyncableUserCode{AC11ED8D-898E-4a1f-AE8E-7631B0FD91E8}:LXwqkabVSg */
    int i = 0;

    Sleep(1);
    /* SyncableUserCode{AC11ED8D-898E-4a1f-AE8E-7631B0FD91E8} */

    do
    {
        /* SyncableUserCode{D32071E0-AF43-44df-A06B-F7371E40289C}:1OXImpP2ti */
        distance = getFirstParam(getLeaderDistance());

        if (i < 2)
        {
            distance = 14;
        }
		if (distance > 12.7) {
			/* SyncableUserCode{D32071E0-AF43-44df-A06B-F7371E40289C} */

			/* SyncableUserCode{3AE64D02-CF15-4a15-A1D2-B80342BCAB1D}:vNW2CEFsvI */
			double speed = 0.0;
			if (distance < 13.5) 
			{
				speed = 15 * (distance * distance) - 360 * distance + 2166.5; // => 82
			}
			else
			{
				speed = (10 * 100) / (10 + (100 - 10)*exp(-(100 * 0.04*(distance - 12.7)))); // => 75
			}
			//speed += 25 * (distance * distance) - 630 * distance + 3983; // 3978.75
			//speed += -5 * (distance * distance) + 170 * distance - 1314;
			//speed += -16.667 * (distance * distance) + 498.3 * distance - 3610;
			//speed /= 2;
			//double speed = (distance - 12.5) * 47.5 + 5; // => 65
			// speed += (50 * pow((distance - 13), 3) + 0.05*(distance - 13) + 50); // => 50

			//speed -= 10;
			if (speed > 100)
			{
				speed = 100;
			}
			else if (speed < 0)
			{
				speed = 0;
			}

			double deltaAngle;
			double deltaX;
			double deltaY;

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
			double leaderAngle = atan(deltaX / deltaY) * 180 / acos(-1.0); // acos(-1.0) = PI
			double roverAngle = getFirstParam(getRoverCompass());

			if (roverAngle > 180)
			{
				roverAngle -= 360;
			}

			deltaAngle = leaderAngle - roverAngle;
			/* SyncableUserCode{121B8AD1-A38E-46cf-A0C5-7F7D9371D728} */

			double leftMultiplier = 1.0 / 10000.0 * pow(deltaAngle, 3) + 0.01*deltaAngle + 1;
			double rightMultiplier = 1.0 / 10000.0 * -pow(deltaAngle, 3) + 0.01*deltaAngle + 1;

			printf("%f %f\n", leftMultiplier, rightMultiplier);

			double leftspeed = leftMultiplier * speed;
			if (leftspeed > 100)
			{
				leftspeed = 100;
			}
			else if (leftspeed < 0)
			{
				leftspeed = 0;
			}

			double rightspeed = rightMultiplier * speed;
			if (rightspeed > 100)
			{
				rightspeed = 100;
			}
			else if (rightspeed < 0)
			{
				rightspeed = 0;
			}
			/* SyncableUserCode{3AE64D02-CF15-4a15-A1D2-B80342BCAB1D} */

			/* SyncableUserCode{97F5C2F7-F60C-44d4-A358-EC4CB5B1CF69}:J5shemUn8N */
			setLRPower((int)leftspeed, (int)rightspeed);
		}
		else
		{
			setLRPower(0, 0);

		}
        /* SyncableUserCode{97F5C2F7-F60C-44d4-A358-EC4CB5B1CF69} */
        /* SyncableUserCode{12B56C32-674D-48f5-93E8-29CAECA988A5}:fSOJnDkv0w */
        Sleep(60);
        /* SyncableUserCode{12B56C32-674D-48f5-93E8-29CAECA988A5} */

        /* SyncableUserCode{0DEBF4E0-A1D6-4c0e-81CD-1A75B7AA9473}:bfu5YXWBGJ */
        i++;
        /* SyncableUserCode{0DEBF4E0-A1D6-4c0e-81CD-1A75B7AA9473} */

		if (i == 1000) {
			setLRPower(0, 0);
		}

    } while (i < 1000);

    return;
}

