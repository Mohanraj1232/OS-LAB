#include<stdio.h>
void main(){
    int n;
    printf("Enter No.of Pages:");
    scanf("%d",&n);
    int page[n],pageSize;
    for(int i=0;i<n;i++){
        page[n]=-1;
    }

    printf("Enter Page Size:");
    scanf("%d",&pageSize);

    printf("ref String       frame no\n");
    for(int i=0;i<n;i++){
        printf("    %d               ",i+1);
        scanf("%d",&page[i]);
    }
    int pno,off;
    printf("Enter the Logical Address i.e(Page Number & Offset):");
    scanf("%d%d",&pno,&off);
    if(pno<=0 || pno>n){
        printf("Invalid Page Number");
        return;
    }
    if(page[pno]==-1){
        printf("The Given Page is Not Present in any Frame:");
        return;
    }
    int frame_no=page[pno];
    int physical_address=frame_no*pageSize+off;
}