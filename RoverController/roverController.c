
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <WinSock2.h>

#include <windows.h>

// function declarations
int setupSocket(int port);
char * sendAndRecv(int networkSocket, char toSend[256]);
void sendAndNoRecv(int networkSocket, char toSend[256]);

void main() {
	WSADATA mywsadata; //your wsadata struct, it will be filled by WSAStartup
	WSAStartup(0x0202, &mywsadata); //0x0202 refers to version of sockets we want to us

									// create a socket
	int observerSocket = setupSocket(9999);
	int roverSocket = setupSocket(9998);

	printf("Connection successful\n");

	printf(sendAndRecv(observerSocket, "ready\n"));

	sendAndNoRecv(roverSocket, "Rover,setLRPower(100,100)\n");

	int i;

	for (i = 0; i < 50; i++) {
		Sleep(500);
		printf("%s\n", sendAndRecv(observerSocket, "Leader,GPS()\n"));
		printf("%s\n", sendAndRecv(observerSocket, "Leader,Distance()\n"));
	}

	printf("Press ENTER key to Continue\n");
	getchar();

	shutdown(observerSocket, 2);
	shutdown(roverSocket, 2);


	return 0;
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
