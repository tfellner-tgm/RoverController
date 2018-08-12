/* ***************************************************
 * Model File: Model::Impelementation::RoverController::RoverController
 * Model Path: C:\Users\Thomas\source\repos\StaticLibrary\RoverControllerModel.eap
 * 
 * 2018-08-12  - 23:20
 * ***************************************************
 *  */
#ifndef H_ROVERCONTROLLER
#define H_ROVERCONTROLLER

#include "roverCommunicationLib.h" /* Include for 'relation to classifier' 'roverCommunicationLib' */
#include <math.h>/* Include for 'relation to classifier' 'math' */
#include <Windows.h>/* Include for 'relation to classifier' 'Windows' */
#include <stdio.h>/* Include for 'relation to classifier' 'stdio' */

typedef int RoverController;

/* Returns a pointer to the statically allocated structure for RoverController.
 * Automatically added and generated.
 * @return Pointer to the statically allocated structure for RoverController. */
RoverController* RoverController_new(void);

/* Activity DistanceHandler of class RoverController */
void RoverController_DistanceHandler(RoverController* const me);

/* Activity AngleHandler of class RoverController */
void RoverController_AngleHandler(RoverController* const me);

#endif /* #ifndef H_ROVERCONTROLLER */

