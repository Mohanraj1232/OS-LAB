#include<stdio.h>
void main(){
    int nop,nof,hit=0,fault=0;
    printf("Enter the No.Of Pages:");
    scanf("%d",&nop);
    printf("Enter the No.Of Frames:");
    scanf("%d",&nof);
    
    int pages[nop],frames[nof],recent[nof];
    for(int i=0;i<nof;frames[i++]=-1);
    for(int i=0;i<nof;recent[i++]=-1);

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
                recent[j]=i;
            }
        }
        if(flag==0){
            int frame_ind=-1;
            for(int k=0;k<nof;k++){
                if(frames[k]==-1){
                    frame_ind=k;
                    break;
                }
            }
            if(frame_ind==-1){
                int min=recent[0];
                frame_ind=0;
                for(int k=1;k<nof;k++){
                    if(min>recent[k]){
                        min=recent[k];
                        frame_ind=k;
                    }
                }
            }
            frames[frame_ind]=pages[i];
            recent[frame_ind]=i;
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
