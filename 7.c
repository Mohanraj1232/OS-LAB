#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main(){

    int key=5679,childpid,shmid;
    char c,*s,*shm;

    shmid=shmget(key,27,IPC_CREAT | 0666);
    shm=shmat(shmid,NULL,0);
    s=shm;
    childpid=fork();
    if(childpid<0){
        perror("ERROR");
        exit(1);
    }

    if(childpid==0){
        for(c='a';c<='z';c++){
            *s++=c;
        }
        *s='\0';
    }else{
        wait(NULL);
        for(s=shm;*s!='\0';s++){
            putchar(*s);
        }
    }
}
