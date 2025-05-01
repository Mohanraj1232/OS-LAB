#include <stdio.h>
void main()
{
    int n, r;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    int alloc[r];
    printf("Enter the total available resources: ");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &alloc[i]);
    }
    int max_alloc[n][r];
    printf("Enter the max allocated resources for each process: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &max_alloc[i][j]);
        }
    }
    int process_alloc[n][r];
    printf("Enter the allocated resources for each process: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &process_alloc[i][j]);
        }
    }
    int need[n][r];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max_alloc[i][j] - process_alloc[i][j];
        }
    }
    int f = 0;
    int arr[n];
    int temp_f = -1;
    int completed[n];
    for (int i = 0; i < n; i++)
    {
        completed[i] = 1;
        arr[i] = 0;
    }
    while (f < n && (temp_f < f))
    {
        temp_f = f;
        for (int i = 0; i < n; i++)
        {
            if (completed[i] == 0)
                continue;
            int flag = 0;
            int temp[r];
            for (int j = 0; j < r; j++)
            {
                if (alloc[j] < need[i][j])
                {
                    flag = 1;
                    continue;
                }
                temp[j] = alloc[j] + process_alloc[i][j];
            }
            if (flag == 0)
            {
                for (int i = 0; i < r; i++)
                {
                    alloc[i] = temp[i];
                }
                completed[i] = 0;
                arr[f++] = i + 1;
            }
        }
    }
    if (f != n)
    {
        printf("Deadlock is present.");
        return;
    }
    printf("The process at which it ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}