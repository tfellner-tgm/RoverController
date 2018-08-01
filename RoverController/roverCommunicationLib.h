/* function declarations */
void setupSockets();
int setupSocket(int port);
void shutdownSockets();
char * sendAndRecv(int networkSocket, char toSend[256]);
void sendAndNoRecv(int networkSocket, char toSend[256]);

char * sendReady();
char * getLeaderGPS();
char * getLeaderDistance();

void setForwardPower(int power);
void incrementPower(int power);
void setLRPower(int left, int right);
void brake(int power);
char * getRoverGPS();
char * getRoverCompass();

double getFirstParam(char response[256]);
double getSecondParam(char response[256]);

/* global variable declarations */
int observerSocket;
int roverSocket;