#include<stdio.h>
void main(){
    int nop,nof,ptr=0,hit=0,fault=0;
    printf("Enter the No.Of Pages:");
    scanf("%d",&nop);
    printf("Enter the No.Of Frames:");
    scanf("%d",&nof);
    
    int pages[nop],frames[nof];
    for(int i=0;i<nof;frames[i++]=-1);

    printf("Enter the Page Numbers:\n");

    for(int i=0;i<nop;i++){
        printf("Page%d:",i+1);
        scanf("%d",&pages[i]);
    }

    printf("\nRef String         Frames\n");
    for(int i=0;i<nop;i++){
        int flag=0;

        for(int j=0;j<nof;j++){
            if(frames[j]==pages[i]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            frames[ptr]=pages[i];
            ptr=(ptr+1)%nof;
            fault++;
        }else{
            hit++;
        }
        printf("    %d              ",pages[i]);
        for(int j=0;j<nof;j++){
            printf("%d ",frames[j]);
        }
        printf("\n");
    }


    printf("No.of Hit=%d\nNo.of Page Faults=%d",hit,fault);


}