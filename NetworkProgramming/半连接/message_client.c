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
	int sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (sock == -1) {
		error_handling("sock() error");
	}
	struct sockaddr_in serv_adr,clnt_adr;
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));
	int str_len = sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
	socklen_t clnt_adr_sz = sizeof(clnt_adr);
	recvfrom(sock, message, str_len, 0, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
	message[str_len] = 0;
	printf("%s\n", message);
	char mes[] = "thank you";
	str_len = sendto(sock, mes, strlen(mes), 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
	close(sock);
	return 0;
}