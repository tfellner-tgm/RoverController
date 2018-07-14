
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <WinSock2.h>

#include <windows.h>

// function declarations
int setupSocket(int port);
char * sendAndRecv(int network_socket, char to_send[256]);
void sendAndNoRecv(int network_socket, char to_send[256]);

void main() {
	WSADATA mywsadata; //your wsadata struct, it will be filled by WSAStartup
	WSAStartup(0x0202, &mywsadata); //0x0202 refers to version of sockets we want to us

	// create sockets
	int observer_socket = setupSocket(9998);
	int rover_socket = setupSocket(9999);

	printf("Connection successful\n");

	printf(sendAndRecv(observer_socket, "ready\n"));
	// printf(sendAndRecv(observer_socket, "ready\n"));
	printf(sendAndRecv(observer_socket, "Leader,GPS()\n"));
	printf(sendAndRecv(observer_socket, "Leader,Distance()\n"));

	printf("%s\n", sendAndRecv(rover_socket, "Rover,GPS()\n"));
	printf("%s\n", sendAndRecv(rover_socket, "Rover,getCompass()\n"));
	Sleep(500);
	printf(sendAndRecv(observer_socket, "Leader,GPS()\n"));
	printf(sendAndRecv(observer_socket, "Leader,Distance()\n"));
	/*
	printf("%s\n", sendAndRecv(observer_socket, "ready\n"));

	sendAndNoRecv(rover_socket, "Rover,setLRPower(100,100)\n");

	int i;

	for (i = 0; i < 50; i++) {
		Sleep(500);
		printf(sendAndRecv(observer_socket, "Leader,GPS()\n"));
		printf(sendAndRecv(observer_socket, "Leader,Distance()\n"));
	}*/
	

	printf("Press ENTER key to Continue\n");
	getchar();

	shutdown(observer_socket, 2);
	shutdown(rover_socket, 2);

	
	return 0;
}

int setupSocket(int port) {
	int socket_connection;
	socket_connection = socket(AF_INET, SOCK_STREAM, 0);

	//specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	// connect to observer
	int connection_status = connect(socket_connection, (struct sockaddr *) &server_address, sizeof(server_address));

	if (connection_status == -1) {
		printf("Error during connection\n");
		exit(1);
	}

	return socket_connection;
}

int connect(int network_socket) {
}

char * sendAndRecv(int network_socket, char to_send[256]) {
	sendAndNoRecv(network_socket, to_send);

	// receive data from the server
	char server_response[256];
	int num = recv(network_socket, &server_response, sizeof(server_response), 0);

	printf(server_response);

	// cut the server response
	char * new_server_response = (char *)malloc(num); // allocate memory for new array, don't forget to free it later
	memcpy(new_server_response, server_response, num); // copy data from old buf to new one

	new_server_response[num] = '\0';

	if (new_server_response[num - 1] == '\n')
		new_server_response[num - 1] = '\0';

	return "\n";
}

void sendAndNoRecv(int network_socket, char to_send[256]) {
	printf(to_send);

	// for some reason have to copy over the array to send it
	char local_to_send[256];
	strncpy_s(local_to_send, 256, to_send, 256);

	int len = strlen(local_to_send);

	// send data to the server
	send(network_socket, local_to_send, len, 0);
}

