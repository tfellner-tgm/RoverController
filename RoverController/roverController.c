
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <WinSock2.h>

#include <windows.h>

// function declarations
char * send_and_recv(int network_socket, char to_send[256]);
void send_and_no_recv(int network_socket, char to_send[256]);

void main() {
	WSADATA mywsadata; //your wsadata struct, it will be filled by WSAStartup
	WSAStartup(0x0202, &mywsadata); //0x0202 refers to version of sockets we want to us

	// create a socket
	int observer_socket;
	observer_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify an address for the socket
	struct sockaddr_in observer_server_address;
	observer_server_address.sin_family = AF_INET;
	observer_server_address.sin_port = htons(9999);
	observer_server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);


	// create a socket
	int rover_socket;
	rover_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify an address for the socket
	struct sockaddr_in rover_server_address;
	rover_server_address.sin_family = AF_INET;
	rover_server_address.sin_port = htons(9998);
	rover_server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	// connect to observer
	int observer_connection_status = connect(observer_socket, (struct sockaddr *) &observer_server_address, sizeof(observer_server_address));

	// connect to rover
	int rover_connection_status = connect(rover_socket, (struct sockaddr *) &rover_server_address, sizeof(rover_server_address));

	if (observer_connection_status == -1 || rover_connection_status == -1) {
		printf("Error during connection\n");
	}
	else {
		printf("Connection successful\n");

		printf("%s\n", send_and_recv(observer_socket, "ready\n"));

		send_and_no_recv(rover_socket, "Rover,setLRPower(100,100)\n");

		int i;

		for (i = 0; i < 50; i++) {
			Sleep(500);
			printf(send_and_recv(observer_socket, "Leader,GPS()\n"));
			printf(send_and_recv(observer_socket, "Leader,Distance()\n"));
		}
	}

	printf("Press ENTER key to Continue\n");
	getchar();

	shutdown(observer_socket, 2);
	shutdown(rover_socket, 2);

	
	return 0;
}

char * send_and_recv(int network_socket, char to_send[256]) {
	send_and_no_recv(network_socket, to_send);

	// receive data from the server
	char server_response[32];
	int num = recv(network_socket, &server_response, sizeof(server_response), 0);

	printf(server_response);

	// 
	char * new_server_response = (char *)malloc(num); // allocate memory for new array, don't forget to free it later
	memcpy(new_server_response, server_response, num); // copy data from old buf to new one

	new_server_response[num] = '\0';            // <<-- Really important bit!

	if (new_server_response[num - 1] == '\n')     // <<-- Nice to have.
		new_server_response[num - 1] = '\0';      // <<-- Nice to have.

	return new_server_response;
}

void send_and_no_recv(int network_socket, char to_send[256]) {
	printf(to_send);

	// for some reason have to copy over the array to send it
	char local_to_send[256];
	strncpy_s(local_to_send, 256, to_send, 256);

	// send data to the server
	send(network_socket, local_to_send, sizeof(local_to_send), 0);
}
