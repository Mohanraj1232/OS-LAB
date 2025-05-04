#include<stdio.h>
#define SIZE 3
int buffer[SIZE],mutex=1,full=0,empty=SIZE;

int wait(int s){
    return --s;
}
int signal(int s){
    return ++s;
}

void main(){
    int ch;
    while(1){
        printf("\nPRODUCER AND CONSUMER PROBLEM\n1.Produce\n2.Consume\n3.Display Buffer Contents\n4.Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(empty==0){
                    printf("\nBuffer is FULL:");
                    break;
                }
                mutex=wait(mutex);
                empty=wait(empty);
                printf("\nEnter A Value:");
                int val;
                scanf("%d",&val);
                buffer[full]=val;
                full=signal(full);
                mutex=signal(mutex);
                break;
            case 2:
                if(full==0){
                    printf("\nBuffer is EMPTY:");
                    break;
                }
                mutex=wait(mutex);
                full=wait(full);
                printf("\nValue Consumed is %d",buffer[0]);
                for(int i=0;i<SIZE-1;i++){
                    buffer[i]=buffer[i+1];
                }
                empty=signal(empty);
                mutex=signal(mutex);
                break;
            case 3:
                if(full==0){
                    printf("\nBuffer is EMPTY:");
                    break;
                }
                printf("\n Buffer Contents: \n");
                for(int i=0;i<full;i++){
                    printf("%d ",buffer[i]);
                }
                printf("\n");
                break;
            case 4:
                return;
            default:
                printf("Invalid Input");
        }

    }

}