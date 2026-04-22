#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
int main(int argc, char *argv[]) {
    char buf[] = "we are the champions!";
    int fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1){
        error_handling("open() error");
    }
    printf("文件描述符: %d\n",fd);
    if(write(fd,buf,sizeof(buf)) == -1){
        error_handling("write() error");
    }
    close(fd);
    return 0;
}