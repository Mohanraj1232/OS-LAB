#include <stdio.h>
void main()
{
    int n;
    printf("Enter the total number of process: ");
    scanf("%d", &n);
    int bt[n], wt[n], tt[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    printf("Gnaat chart: \n ");
    for (int i = 0; i < n; i++)
    {
        printf("------   ");
    }
    printf("\n ");
    for (int i = 0; i < n; i++)
    {
        printf("  P%d   | ", i + 1);
    }
    printf("\n ");
    for (int i = 0; i < n; i++)
    {
        printf("------   ");
    }
    printf("\n0");
    int sums = 0, twt = 0, ttt = 0;
    for (int i = 0; i < n; i++)
    {
        wt[i] = sums;
        twt += wt[i];
        sums += bt[i];
        tt[i] = sums;
        ttt += tt[i];
        printf("       %d ", sums);
    }
    printf("\n");
    printf("PROCESS  BURSTTIME  WAITINGTIME  TURNAROUND TIME\n");
    for (int i = 0; i < n; i++)
    {
        printf("   %d         %d           %d              %d\n", i + 1, bt[i], wt[i], tt[i]);
    }
    printf("Total waiting time: %d\n", twt);
    printf("Total turn around time: %d\n", ttt);
    printf("Average waiting time: %.2f\n", twt * 1.0 / n);
    printf("Average turn around time: %.2f\n", ttt * 1.0 / n);
}