#include <stdio.h>

struct process
{
    int burst, wait, tat;
} p[20];

int main()
{
    int n, i;
    float total_wait = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].burst);
    }

    
    p[0].wait = 0;

    
    for (i = 1; i < n; i++)
    {
        p[i].wait = p[i - 1].wait + p[i - 1].burst;
    }

    
    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].wait + p[i].burst;
        total_wait += p[i].wait;
        total_tat += p[i].tat;
    }


    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n", i + 1, p[i].burst, p[i].wait, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
