/* ***************************************************
 * Model File: Model::Impelementation::RoverController::Main
 * Model Path: C:\Users\Thomas\source\repos\StaticLibrary\RoverControllerModel.eap
 * 
 * 2018-08-06  - 14:32
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
    /* SyncableUserCode{05E46EA2-BBBF-4249-8908-5AB399ED732C}:Nbrlk8aPUZ */
	RoverController* rc = RoverController_new();
	RoverController_RoverController(rc);

    /* SyncableUserCode{05E46EA2-BBBF-4249-8908-5AB399ED732C} */
}

