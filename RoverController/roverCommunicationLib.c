
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <WinSock2.h>

#include <windows.h>
#include "roverCommunicationLib.h"

void main() {
	setupSockets();

	printf(sendReady());
	setLRPower(100, 100);

	Sleep(2000);

	char * distance = getLeaderDistance();
	printf("%s\n", distance);
	printf("%f\n", getFirstParam(distance));
	// printf("%f", getSecondParam(getRoverGPS()));
	// printf("%f", getSecondParam(getLeaderGPS()));

	printf("Press ENTER key to Continue\n");
	getchar();

	shutdownSockets();

	return 0;
}

void setupSockets() {
	WSADATA mywsadata; //your wsadata struct, it will be filled by WSAStartup
	WSAStartup(0x0202, &mywsadata); //0x0202 refers to version of sockets we want to us

	observerSocket = setupSocket(9999);
	roverSocket = setupSocket(9998);

	printf("Connection successful\n");
}

int setupSocket(int port) {
	// create a socket
	int socketConnection;
	socketConnection = socket(AF_INET, SOCK_STREAM, 0);

	//specify an address for the socket
	struct sockaddr_in socketAddress;
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_port = htons(port);
	socketAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	// connect to observer
	int connectionStatus = connect(socketConnection, (struct sockaddr *) &socketAddress, sizeof(socketAddress));

	if (connectionStatus == -1) {
		printf("Error during connection\n");
		exit(1);
	}

	return socketConnection;
}

void shutdownSockets() {
	shutdown(observerSocket, 2);
	shutdown(roverSocket, 2);
}

char * sendAndRecv(int networkSocket, char toSend[256]) {
	sendAndNoRecv(networkSocket, toSend);

	// receive data from the server
	char server_response[32];
	int num = recv(networkSocket, &server_response, sizeof(server_response), 0);

	char * newServerResponse = (char *)malloc(num); // allocate memory for new array, don't forget to free it later
	memcpy(newServerResponse, server_response, num); // copy data from old buf to new one

	newServerResponse[num] = '\0';

	if (newServerResponse[num - 1] == '\n')
		newServerResponse[num - 1] = '\0';

	return newServerResponse;
}

void sendAndNoRecv(int networkSocket, char toSend[256]) {
	printf("%s", toSend);

	// for some reason have to copy over the array to send it
	char localToSend[256];
	strncpy_s(localToSend, 256, toSend, 256);

	// send data to the server
	send(networkSocket, localToSend, strlen(localToSend), 0);
}

char * sendReady() {
	return sendAndRecv(observerSocket, "ready\n");
}

char * getLeaderGPS() {
	return sendAndRecv(observerSocket, "Leader,GPS()\n");
}

char * getLeaderDistance() {
	return sendAndRecv(observerSocket, "Leader,Distance()\n");
}

void setForwardPower(int power) {
	char buf[256];
	sprintf_s(buf, 256, "Rover,setForwardPower(%d)\n", power);
	sendAndNoRecv(roverSocket, buf);
}

void incrementPower(int power) {
	char buf[256];
	sprintf_s(buf, 256, "Rover,incrementPower(%d)\n", power);
	sendAndNoRecv(roverSocket, buf);
}

void setLRPower(int left, int right) {
	char buf[256];
	sprintf_s(buf, 256, "Rover,setLRPower(%d,%d)\n", left, right);
	sendAndNoRecv(roverSocket, buf);
}

void brake(int power) {
	char buf[256];
	sprintf_s(buf, 256, "Rover,brake(%d)\n", power);
	sendAndNoRecv(roverSocket, buf);
}

char * getRoverGPS() {
	return sendAndRecv(roverSocket, "Rover,GPS()\n");
}

char * getRoverCompass() {
	return sendAndRecv(roverSocket, "Rover,getCompass()\n");
}

double getFirstParam(char response[256]) {
	char *next_token;
	char * p = strtok_s(response, ",", &next_token);
	p = strtok_s(NULL, ",", &next_token);

	return atof(p);
}

double getSecondParam(char response[256]) {
	char *next_token;
	char * p = strtok_s(response, ",", &next_token);
	p = strtok_s(NULL, ",", &next_token);
	p = strtok_s(NULL, ",", &next_token);

	return atof(p);
}