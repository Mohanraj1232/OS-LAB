#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    int SIZE;
    printf("Enter No.of Files:");
    scanf("%d",&SIZE);

    char Files[SIZE][10];
    int FileSize[SIZE],BlockSize[SIZE],NBlocks[SIZE];
    int **BlockNumbers;

    BlockNumbers=(int **)malloc(SIZE * sizeof(int *));

    for(int i=0;i<SIZE;i++){
        printf("Enter the File%d Name:",i+1);
        scanf("%s",Files[i]);
        printf("Enter File Size(In KB):");
        scanf("%d",&FileSize[i]);
        printf("Enter Block Size(In Bytes):");
        scanf("%d",&BlockSize[i]);
        NBlocks[i]=((FileSize[i]*1024)/BlockSize[i]);
        if((FileSize[i]*1024)%BlockSize[i]!=0) NBlocks[i]++;
        BlockNumbers[i]=(int *)malloc(NBlocks[i]*sizeof(int));
        for(int j=0;j<NBlocks[i];j++){
            printf("Enter Number For Block%d:",j+1);
            scanf("%d",&BlockNumbers[i][j]);
        }
        printf("\n");
    }

    char name[10];
    printf("Enter File Name to Display:");
    scanf("%s",&name);

    for(int i=0;i<SIZE;i++){
        if(strcmp(name,Files[i])==0){
            printf("\nName\tSize(In KB)\tBlock Size(In Bytes)\tNBlocks\tBlocks\n");
            printf("%s\t%d\t%d\t%d\t%d",Files[i],FileSize[i],BlockSize[i],NBlocks[i],BlockNumbers[i][0]);
            for(int j=1;j<NBlocks[i];j++){
                printf("->%d",BlockNumbers[i][j]);
            }
            break;
        }
    }

}