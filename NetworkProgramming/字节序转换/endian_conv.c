#include<stdio.h>
#include<arpa/inet.h>

int main() {
	unsigned short hpost = 0x1234;
	unsigned long hip = 0x12345678;
	unsigned short npost = htons(hpost);
	unsigned long nip = htonl(hip);
	printf("主机字节序端口号: %#x\n", hpost);
	printf("网络字节序端口号: %#x\n", npost);
	printf("主机字节序IP: %#lx\n", hip);
	printf("主机字节序IP: %#Lx\n", nip);
	return 0;
}