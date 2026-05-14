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
    if(argc != 3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }
	int sock = socket(PF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in serv_addr,clnt_addr;
	socklen_t clnt_adr_sz;
	char message[BUF_SIZE];
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));
	while (1) {
		printf("请输入信息: ");
		fgets(message, BUF_SIZE, stdin);
		if (strcmp(message, "Q\n") == 0 || strcmp(message, "q\n") == 0) {
			break;
		}
		int str_len = sendto(sock, message, sizeof(message),0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
		recvfrom(sock, message, str_len, 0, (struct sockaddr*)&clnt_addr, &clnt_adr_sz);
		message[str_len] = 0;
        printf("从服务器接收的信息: %s", message);
	}
	close(sock);
	return 0;
}