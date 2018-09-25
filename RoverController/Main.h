/* ***************************************************
 * Model File: Model::Impelementation::RoverController::Main
 * Model Path: C:\Users\Thomas\source\repos\RoverController2\RoverControllerModel.eap
 * 
 * 2018-09-25  - 16:12
 * ***************************************************
 *  */
#ifndef H_MAIN
#define H_MAIN

#include "roverCommunicationLib.h" /* Include for 'relation to classifier' 'roverCommunicationLib' */
#include "RoverController.h" /* Include for 'relation to classifier' 'RoverController' */
#include <stdio.h>/* Include for 'relation to classifier' 'stdio' */
#include <math.h>/* Include for 'relation to classifier' 'math' */
#include <time.h>/* Include for 'relation to classifier' 'time' */
#include <Windows.h>/* Include for 'relation to classifier' 'Windows' */

typedef int Main;

/* Returns a pointer to the statically allocated structure for Main.
 * Automatically added and generated.
 * @return Pointer to the statically allocated structure for Main. */
Main* Main_new(void);

/* Operation 'main' of class 'Main' */
int main(Main* const me);

/* Operation 'DistanceHandler' of class 'Main' */
DWORD WINAPI Main_DistanceHandler(Main* const me);

/* Operation 'AngleHandler' of class 'Main' */
DWORD WINAPI Main_AngleHandler(Main* const me);

#endif /* #ifndef H_MAIN */

