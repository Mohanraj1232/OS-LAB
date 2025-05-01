#include <stdio.h>

void main()
{
    int n;
    printf("Enter the total number of process: ");
    scanf("%d", &n);
    int bt[n], wt[n], tt[n],quant,noofboxes=0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    printf("Enter the Quant:"); //i=actual process ptr=noofboxes
    scanf("%d",&quant);
    for (int i = 0; i < n; i++)
    {
        noofboxes+=(bt[i]%quant==0)?bt[i]/quant:(bt[i]/quant)+1;
    }
    int newbt[noofboxes][2],ptr=0,i=0;
    while(ptr<noofboxes){
        if(bt[i]>0){
            newbt[ptr][0]=i+1;
            newbt[ptr][1]=(bt[i]>=quant)?quant:bt[i];
            bt[i]-=quant;
            i=(i+1)%n;
            ptr++;
        }else{
            i=(i+1)%n;
        }
    }

    printf("Gnaat chart: \n ");
    for (int i = 0; i < noofboxes; i++)
    {
        printf("------   ");
    }
    printf("\n|");
    for (int i = 0; i < noofboxes; i++)
    {
        printf("  P%d   | ", newbt[i][0]);
    }
    printf("\n ");
    for (int i = 0; i < noofboxes; i++)
    {
        printf("------   ");
    }
    printf("\n0");
    int sums=0,pt[n];
    for(int i=0;i<n;pt[i++]=0);

    for (int i = 0; i < noofboxes; i++)
    {
        if(pt[newbt[i][0]-1]==0){
            bt[newbt[i][0]-1]=newbt[i][1];
            pt[newbt[i][0]-1]=sums+newbt[i][1];
            wt[newbt[i][0]-1]=sums;
        }else{
            bt[newbt[i][0]-1]+=newbt[i][1];
            wt[newbt[i][0]-1]+=sums-pt[newbt[i][0]-1];
            pt[newbt[i][0]-1]=sums+newbt[i][1];
        }
        sums += newbt[i][1];

        printf("       %d ", sums);
    }
    printf("\n");
    int twt = 0, ttt = 0;
    printf("PROCESS  BURSTTIME  WAITINGTIME  TURNAROUND TIME\n");
    for (int i = 0; i < n; i++)
    {
        printf("   %d         %d           %d              %d\n", i + 1, bt[i], wt[i], bt[i]+wt[i]);
        twt+=wt[i];
        ttt+=wt[i]+bt[i];
    }
    printf("Total waiting time: %d\n", twt);
    printf("Total turn around time: %d\n", ttt);
    printf("Average waiting time: %.2f\n", twt * 1.0 / n);
    printf("Average turn around time: %.2f\n", ttt * 1.0 / n);
}