#include<stdio.h>
void main(){
    int F[100],st,len;
    for(int i=0;i<100;F[i++]=0);
    
    while(1){
        printf("Enter The Start and Length of the File:\nStart:");
        scanf("%d",&st);
        printf("Length:");
        scanf("%d",&len);

        if(st<0 || st>=100 || st+len>=100 || len<=0){
            printf("Invalid Details\n");
        }else{
            int flag = 0;
            for(int i=st;i<st+len;i++){
                if(F[i]==1){
                    flag=1;
                    break;
                }
            }

            if(flag==0){
                for(int i=st;i<st+len;i++){
                    F[i]=1;
                }
                printf("\nFile Allocated Succesfully");
            }else{
                printf("\nFile Cannot be Allocatted");
            }
        }
        int ch;
        printf("\nDo you want to continue(Yes-1:No-0):");
        scanf("%d",&ch);
        if(ch!=1){
            break;
        }
    }
}