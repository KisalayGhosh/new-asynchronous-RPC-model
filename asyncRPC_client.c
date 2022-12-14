/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "asyncRPC.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>










int callSocketClient(int portNumber)
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[1024];
	
	
	portno = portNumber; // Port number in integer
	
	//printf("%d\n",portno);
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		printf("ERROR opening socket");
	server = gethostbyname("localhost"); // Host name to IP number
	
	if (server == NULL)
		printf("ERROR, no such host\n");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	
	
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))< 0)
		printf("ERROR in connecting");
		
	//printf("%d\n",connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)));
	
	printf("Please enter username : "); // Input prompt for client msg.
	
	bzero(buffer,1024);
	fgets(buffer,1024,stdin); // Get the msg from stdin
	n = write(sockfd,buffer,strlen(buffer));
	
	//printf("Please enter password : ");
	char *ch;
	ch = getpass("Please enter password :");
	
	
	bzero(buffer,1024);
	
	strcpy(buffer,ch);
	//fgets(buffer,1024,stdin); // Get the msg from stdin
	n = write(sockfd,buffer,strlen(buffer));
	
	//printf("%d\n",n);
	
	if (n < 0)
		printf("ERROR writing to socket");
	
	
	int success = 0, fail = 0;
	bzero(buffer,1024);
	n = read(sockfd,buffer,1024);
	if (n < 0)
		printf("ERROR reading from socket");
	
	if(buffer[0] == '0')
	{
		printf("Login successfull! \n");
		success++;
	}
	else
	{
		printf("Incorrect username or password! Please try again.\n");
		fail++;
	}
	//printf("Server replies: %s\n",buffer);
	close(sockfd);
	//close();
	if(success == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}





int call_issuebook_Client(int portNumber)
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[1024];
	
	
	portno = portNumber; // Port number in integer
	
	//printf("%d\n",portno);
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		printf("ERROR opening socket");
	server = gethostbyname("localhost"); // Host name to IP number
	
	if (server == NULL)
		printf("ERROR, no such host\n");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	
	
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))< 0)
		printf("ERROR in connecting\n");
		
	//printf("%d\n",connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)));
	
	printf("\n\n\n\nHere are the following books available in our library.\n\n\n\n");
	
	char *file_read;
	FILE *fptr;
	size_t len = 0;
    	ssize_t reading;
    	fptr = fopen("book.txt", "r");
    	
	while ((reading = getline(&file_read, &len, fptr)) != -1) 
    	{
        	
        	printf("%s\n",file_read);
        	
    	}
    	
    	fclose(fptr); 
	
	printf("\n\n\n\nPlease enter book_id to be issued : "); // Input prompt for client msg.
	printf("\n\n");
	bzero(buffer,1024);
	fgets(buffer,1024,stdin); // Get the msg from stdin
	n = write(sockfd,buffer,strlen(buffer));
	
	/*printf("Please enter password : ");
	
	bzero(buffer,1024);
	fgets(buffer,1024,stdin); // Get the msg from stdin
	n = write(sockfd,buffer,strlen(buffer));*/
	
	//printf("%d\n",n);
	
	if (n < 0)
		printf("ERROR writing to socket");
	
	
	bzero(buffer,1024);
	n = read(sockfd,buffer,1024);
	if (n < 0)
		printf("ERROR reading from socket");
	
	
	if(buffer[0] == '0')
	{
		printf("No such book exists!\n");
	}
	else
	{
		printf("Book issued successfully.\nNumber of this book left = %s\n",buffer);
	}
	
	//printf("Server replies: %s\n",buffer);
	close(sockfd);
	//close();
	
	return 1;
}






int call_returnbook_Client(int portNumber)
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[1024];
	
	
	portno = portNumber; // Port number in integer
	
	//printf("%d\n",portno);
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		printf("ERROR opening socket");
	server = gethostbyname("localhost"); // Host name to IP number
	
	if (server == NULL)
		printf("ERROR, no such host\n");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	
	
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))< 0)
		printf("ERROR in connecting");
		
	//printf("%d\n",connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)));
	
	printf("Please enter book_id to be returned : "); // Input prompt for client msg.
	
	bzero(buffer,1024);
	fgets(buffer,1024,stdin); // Get the msg from stdin
	n = write(sockfd,buffer,strlen(buffer));
	
	/*printf("Please enter password : ");
	
	bzero(buffer,1024);
	fgets(buffer,1024,stdin); // Get the msg from stdin
	n = write(sockfd,buffer,strlen(buffer));*/
	
	//printf("%d\n",n);
	
	if (n < 0)
		printf("ERROR writing to socket");
	
	
	bzero(buffer,1024);
	n = read(sockfd,buffer,1024);
	if (n < 0)
		printf("ERROR reading from socket");
	
	
	if(buffer[0] == '0')
	{
		printf("No such book exists!\n");
	}
	else
	{
		printf("Book has been returned successfully.\nNumber of this book left = %s\n",buffer);
	}
	
	//printf("Server replies: %s\n",buffer);
	close(sockfd);
	//close();
	
	return 1;
}






int call_showallbook_Client(int portNumber)
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[1024];
	
	
	portno = portNumber; // Port number in integer
	
	//printf("%d\n",portno);
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		printf("ERROR opening socket");
	server = gethostbyname("localhost"); // Host name to IP number
	
	if (server == NULL)
		printf("ERROR, no such host\n");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	
	
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))< 0)
		printf("ERROR in connecting");
		
	//printf("%d\n",connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)));
	
	//printf("Please enter book_id to be issued : "); // Input prompt for client msg.
	
	/*bzero(buffer,1024);
	fgets(buffer,1024,stdin); // Get the msg from stdin
	n = write(sockfd,buffer,strlen(buffer));*/
	
	/*printf("Please enter password : ");
	
	bzero(buffer,1024);
	fgets(buffer,1024,stdin); // Get the msg from stdin
	n = write(sockfd,buffer,strlen(buffer));*/
	
	//printf("%d\n",n);
	
	/*if (n < 0)
		printf("ERROR writing to socket");*/
	
	
	
	char *file_read;
	FILE *fptr;
	size_t len = 0;
    	ssize_t reading;
    	fptr = fopen("book.txt", "r");
    	
	while ((reading = getline(&file_read, &len, fptr)) != -1) 
    	{
        	
        	printf("%s\n",file_read);
        	
    	}
    	
    	fclose(fptr);
       	
       	
	
	
	
	bzero(buffer,1024);
	n = read(sockfd,buffer,1024);
	//puts(buffer);
	if (n < 0)
		printf("ERROR reading from socket");
	
	
	//printf("Server replies: %s\n",buffer);
	close(sockfd);
	//close();
	
	return 1;
}









void
asynchronousrpc_prog_11(char *host,int port1)
{
	CLIENT *clnt;
	void  *result_1;
	authenticateDatatype  authenticate_1_arg;
	void  *result_2;
	showAllBooksDatatype  showallbooks_1_arg;
	void  *result_3;
	isuueBookDatatype  isuuebook_1_arg;
	void  *result_4;
	returnBookDatatype  returnbook_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ASYNCHRONOUSRPC_PROG, ASYNCHRONOUSRPC_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	//Starting client socket..
	
	
	authenticate_1_arg.userId = 0;
	authenticate_1_arg.password = 1;
	authenticate_1_arg.portNo = port1;
	
	authenticate_1(&authenticate_1_arg, clnt);
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


void
asynchronousrpc_prog_12(char *host,int port1)
{
	CLIENT *clnt;
	void  *result_1;
	authenticateDatatype  authenticate_1_arg;
	void  *result_2;
	showAllBooksDatatype  showallbooks_1_arg;
	void  *result_3;
	isuueBookDatatype  isuuebook_1_arg;
	void  *result_4;
	returnBookDatatype  returnbook_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ASYNCHRONOUSRPC_PROG, ASYNCHRONOUSRPC_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	//Starting client socket..
	
	
	
	showallbooks_1_arg.portNo = port1;
	
	//authenticate_1(&authenticate_1_arg, clnt);
	
	showallbooks_1(&showallbooks_1_arg, clnt);
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}






void
asynchronousrpc_prog_13(char *host,int port1)
{
	CLIENT *clnt;
	void  *result_1;
	authenticateDatatype  authenticate_1_arg;
	void  *result_2;
	showAllBooksDatatype  showallbooks_1_arg;
	void  *result_3;
	isuueBookDatatype  isuuebook_1_arg;
	void  *result_4;
	returnBookDatatype  returnbook_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ASYNCHRONOUSRPC_PROG, ASYNCHRONOUSRPC_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	//Starting client socket..
	
	
	isuuebook_1_arg.userId = 0;
	isuuebook_1_arg.bookId = 1;
	isuuebook_1_arg.portNo = port1;
	
	//authenticate_1(&authenticate_1_arg, clnt);
	
	isuuebook_1(&isuuebook_1_arg, clnt);
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}



void
asynchronousrpc_prog_14(char *host,int port1)
{
	CLIENT *clnt;
	void  *result_1;
	authenticateDatatype  authenticate_1_arg;
	void  *result_2;
	showAllBooksDatatype  showallbooks_1_arg;
	void  *result_3;
	isuueBookDatatype  isuuebook_1_arg;
	void  *result_4;
	returnBookDatatype  returnbook_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ASYNCHRONOUSRPC_PROG, ASYNCHRONOUSRPC_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	//Starting client socket..
	
	
	returnbook_1_arg.userId = 0;
	returnbook_1_arg.bookId = 1;
	returnbook_1_arg.portNo = port1;
	
	//authenticate_1(&authenticate_1_arg, clnt);
	
	returnbook_1(&returnbook_1_arg, clnt);
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}







int
main (int argc, char *argv[])
{
	char *host;
	int port1 = atoi(argv[2]);
	

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	
	
	
	
	
	int count = 0, type;
	
	printf("\n\n\n\n---------------Welcome to PK Kelkar Library of IIT Kanpur---------------\n\n\n\n");
	
label1:	asynchronousrpc_prog_11 (host,port1);
	
	//asynchronousrpc_prog_1 (host);
	int var1 = callSocketClient(port1);
	//printf("%d\n",var1);
	port1++;
	
	
	char string[50];
		
	
	
	if(var1 == 1)
	{
		printf("\n\n\n\n---------------Welcome to PK Kelkar Library of IIT Kanpur---------------\n");
		printf("\n\n\n\nPress and enter...\n");
		printf("1..........Show all Books\n");
		printf("2..........Issue a Book\n");
		printf("3..........Return a Book\n");
		printf("4..........Contact Us\n");
		printf("5..........About Us\n\n\n\n");
		
	label2:	fgets(string, 49, stdin);
		type = atoi(string);
		
		
		/*asynchronousrpc_prog_13 (host,port1);
		call_issuebook_Client(port1);
		port1++;*/
		
		
		if(type == 1)
		{
			asynchronousrpc_prog_12 (host,port1);
			int var2 = call_showallbook_Client(port1);
			port1++;
		}
		
		else if(type == 2)
		{
			asynchronousrpc_prog_13 (host,port1);
			int var2 = call_issuebook_Client(port1);
			port1++;
		}
		
		else if(type == 3)
		{
			asynchronousrpc_prog_14 (host,port1);
			int var2 = call_returnbook_Client(port1);
			port1++;
		}
		
		else if(type == 4)
		{
			printf("\n\n\n\n--------------------------------------\n");
			printf("\nFeel free to reach us.\nAvijit Roy : 7797690671\nManish Mazumder : 9733601118\n");
			printf("\n--------------------------------------\n\n\n\n");
		}
		
		else if(type == 5)
		{
			printf("\n\n\n\n-------------------------------------------\n");
			printf("\nHi all! Welcome to our website.\nOurselves Avijit Roy and Manish Mazumder.\nWe are master's students at IIT Kanpur.\n");
			printf("\n-------------------------------------------\n\n\n\n");
		}
		
		else
		{
			printf("Enter a valid input\n");
			goto label2;
		}
	
		
	}
	else
	{	count++;
		port1++;
		if(count == 3)
		{
			
			printf("\n\n\n\nYou have entered incorrect username or password maximum number of times!\nPlease try after sometime.\n");
			
		}
		else
		{
			goto label1;
		}
	}
	/*asynchronousrpc_prog_13 (host,port1);
	
	//asynchronousrpc_prog_1 (host);
	var1 = callSocketClient(port1);
	port1++;
	
	asynchronousrpc_prog_14 (host,port1);
	
	//asynchronousrpc_prog_1 (host);
	var1 = callSocketClient(port1);
	port1++;*/
	
	
	
	
	return 0;
}
