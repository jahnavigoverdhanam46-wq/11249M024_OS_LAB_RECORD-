#include <stdio.h>

int main()
{
    int n, i, time = 0, remain, qt;
    int bt[30], rt[30], wt[30], tat[30];
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &qt);

    
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  
        wt[i] = 0;
    }

    remain = n;

    
    while (remain > 0)
    {
        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0)
            {
                if (rt[i] > qt)
                {
                    time += qt;
                    rt[i] -= qt;
                }
                else
                {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                    remain--;
                }
            }
        }
    }

    
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nTotal Waiting Time = %.2f", total_wt);
    printf("\nAverage Waiting Time = %.2f", total_wt / n);

    printf("\nTotal Turnaround Time = %.2f", total_tat);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
