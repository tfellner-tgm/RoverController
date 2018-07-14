// function declarations
char * sendAndRecv(int network_socket, char to_send[256]);
void sendAndNoRecv(int network_socket, char to_send[256]);
int setupSocket(int port);