#include<stdio.h>
struct process
{
      int pid, at, bt, wt, tt;
}p[10];  
void sort(struct process p[], int n)
{
        int i, j;
        struct process temp;
        for (i=0; i<n-1; i++)
        {
                for (j=0; j<n-i-1; j++)
                {
                        if (p[j].at > p[j+1].at)
                        {
                                temp = p[j];
                                p[j] = p[j+1];
                                p[j+1] = temp;
                        }
                }
        }
}
void main()
{
        int n;
        printf ("\nEnter the number of processes: ");
        scanf ("%d", &n);
        for (int i=0; i<n; i++)
        {
                p[i].pid=i;
                printf ("\nEnter the Arrival time of %dth Process: ", i);
                scanf ("%d", &p[i].at);
                printf ("\nEnter the Burst time of %dth Process: ", i);
                scanf ("%d", &p[i].bt);
        }
        sort(p, n);
        int ct[n];
        ct[0] = p[0].at + p[0].bt;
        for (int i=1; i<n; i++)
        {
                ct[i] = ct[i-1] + p[i].bt;
        }
        p[0].wt = 0;
        for (int i=1; i<n; i++)
        {
                p[i].wt = ct[i-1] - p[i].at;
        }
        p[0].tt = p[0].wt + p[0].bt;
        for (int i=1; i<n; i++)
        {
                p[i].tt = ct[i] - p[i].at;
        }
        printf ("\nP.No.\tAT\tBT\tCT\tTAT\tWT");
        for (int i=0; i<n; i++)
        {
                printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i].pid, p[i].at, p[i].bt, ct[i], p[i].tt, p[i].wt);
        }
        int tottt=0;
        int totwt=0;
        for (int i=0; i<n; i++)
        {
                tottt+=p[i].tt;
                totwt+=p[i].wt;
        }
        float avg1=tottt/n;
        float avg2=totwt/n;
        printf ("\nAverage Turnaround Time: %f", avg1);
        printf ("\nAverage Waiting Time: %f", avg2);
}

