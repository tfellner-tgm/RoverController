/* ***************************************************
 * Model File: Model::Impelementation::RoverController::RoverController
 * Model Path: C:\Users\Thomas\source\repos\StaticLibrary\RoverControllerModel.eap
 * 
 * 2018-08-07  - 01:04
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
    /* start of activity code */
    /* SyncableUserCode{97F5C2F7-F60C-44d4-A358-EC4CB5B1CF69}:1PCs0k8xVQ */
    setLRPower(100, 100);
    /* SyncableUserCode{97F5C2F7-F60C-44d4-A358-EC4CB5B1CF69} */

    /* SyncableUserCode{12B56C32-674D-48f5-93E8-29CAECA988A5}:khlzbGeLf9 */
    Sleep(2000);
    /* SyncableUserCode{12B56C32-674D-48f5-93E8-29CAECA988A5} */

    /* SyncableUserCode{D32071E0-AF43-44df-A06B-F7371E40289C}:2QLhAqrjw5 */
    char* distance = getLeaderDistance();
    printf("%s\n", distance);
    printf("%f\n", getFirstParam(distance));
    // printf("%f", getSecondParam(getRoverGPS()));
    // printf("%f", getSecondParam(getLeaderGPS()));

    printf("Press ENTER key to Continue\n");
    getchar();
    /* SyncableUserCode{D32071E0-AF43-44df-A06B-F7371E40289C} */

    return;
}

/* Activity AngleHandler of class RoverController */
void RoverController_AngleHandler(RoverController* const me)
{
    /* start of activity code */
    return;
}

