/* ***************************************************
 * Model File: Model::Impelementation::RoverController::Main
 * Model Path: C:\Users\Thomas\source\repos\RoverController2\RoverControllerModel.eap
 * 
 * 2018-09-25  - 16:12
 * ***************************************************
 *  */
#include "Main.h"

/* Statically allocated instance. Automatically added and generated. */
Main Main_me;

/* Returns a pointer to the statically allocated structure for Main.
 * Automatically added and generated.
 * @return Pointer to the statically allocated structure for Main. */
Main* Main_new(void)
{
    return &Main_me;
}

/* Operation 'main' of class 'Main' */
int main(Main* const me)
{
    /* SyncableUserCode{05E46EA2-BBBF-4249-8908-5AB399ED732C}:z2ryPMn2O9 */
    // setup sockets and print ready statements
    setupSockets();
    printf("%s\n", sendReady());

    // Data of Thread 1
    int DistanceHandlerData = 1;
    // Data of Thread 2
    int AngleHandlerData = 2;
    // Array to store thread handles
    HANDLE ThreadHandles[2];

    // Create Handles
    HANDLE distanceHandler = CreateThread(NULL, 0, Main_DistanceHandler, &DistanceHandlerData, 0, NULL);
    if (distanceHandler == NULL)
        ExitProcess(DistanceHandlerData);

    HANDLE angleHandler = CreateThread(NULL, 0, Main_AngleHandler, &AngleHandlerData, 0, NULL);
    if (angleHandler == NULL)
        ExitProcess(AngleHandlerData);

    ThreadHandles[0] = distanceHandler;
    ThreadHandles[1] = angleHandler;

    WaitForMultipleObjects(2, ThreadHandles, TRUE, INFINITE);

    brake(100);

    // shutdown sockets
    shutdownSockets();

    // Close all thread handles upon completion.
    CloseHandle(distanceHandler);
    CloseHandle(angleHandler);
    /* SyncableUserCode{05E46EA2-BBBF-4249-8908-5AB399ED732C} */
}

/* Operation 'DistanceHandler' of class 'Main' */
DWORD WINAPI Main_DistanceHandler(Main* const me)
{
    /* SyncableUserCode{EDFE8A71-1582-42a1-8C6D-9CE8C12403EA}:UJNFDtjhDB */
    RoverController* rc = RoverController_new();
    RoverController_DistanceHandler_init(rc, &rc->DistanceHandler);
    while (rc->DistanceHandler.mainState.activeSubState != RoverController_DistanceHandler_DistanceHandler_FINAL_1)
    {
        RoverController_DistanceHandler(rc, &rc->DistanceHandler, NOSIG);
    }

    /* SyncableUserCode{EDFE8A71-1582-42a1-8C6D-9CE8C12403EA} */
}

/* Operation 'AngleHandler' of class 'Main' */
DWORD WINAPI Main_AngleHandler(Main* const me)
{
    /* SyncableUserCode{4F14616D-3327-454b-91C8-EC525290E921}:hCvBs55XmC */
    RoverController* rc = RoverController_new();
    RoverController_AngleHandler(rc);

    /* SyncableUserCode{4F14616D-3327-454b-91C8-EC525290E921} */
}

