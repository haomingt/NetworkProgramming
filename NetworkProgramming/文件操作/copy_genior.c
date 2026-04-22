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
    char buf[1];
   int patse_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,0644);
    if(patse_fd == -1)
        error_handling("patse open() error"); 
    int flag;
    while((flag = read(copy_fd,buf,sizeof(buf))) != 0) {
        if(flag == -1){
            error_handling("read() error");
        }
       if(write(patse_fd,buf,sizeof(buf)) == -1){
        error_handling("write() error");
       }
    }
    close(copy_fd);
    close(patse_fd);
    return 0;
}