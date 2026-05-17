#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define BUF_SIZE 30
void error_handling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	char message[] = "I'm Nethan,nice to meet you!";
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		error_handling("sock() error");
	}
	struct sockaddr_in serv_adr, clnt_adr;
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));
	if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("connect() error");
	int str_len = write(sock, message, strlen(message));
	while(read(sock, message, 1)!=0);
	message[str_len] = 0;
	printf("%s\n", message);
	char mes[] = "thank you";
	str_len = write(sock, mes, strlen(mes));
	close(sock);
	return 0;
}