#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void error_handling(char *message) {
    fputs(message,stderr);
    fputc('\n',stderr);
    exit(1);
}
int main(int argc,char *argv[]) {
    if(argc != 3) {
        printf("Usage : %s <pathname>\n",argv[0]);
        exit(1);
    }
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);
    int copy_fd = open(argv[1],O_RDONLY);
    if(copy_fd == -1)
        error_handling("copy open() error");
    char buf[1024] = {0};
    if(read(copy_fd,buf,sizeof(buf)) == -1)
        error_handling("read() error");
    close(copy_fd);
    printf("copy file : %s\n",buf);
    int patse_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,0644);
    if(patse_fd == -1)
        error_handling("patse open() error");
    if(write(patse_fd,buf,sizeof(buf)) == -1){
        error_handling("write() error");
    }
    close(patse_fd);
    return 0;
} 