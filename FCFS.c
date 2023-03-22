#include<stdio.h>
struct process
{
      int pid, at, bt, ct, tt, wt;
}p[10];  
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
                printf ("\nEnter the Completion time of %dth Process: ", i);
                scanf ("%d", &p[i].ct);
        }
        p[0].wt=0;
        p[0].ct=p[0].bt+p[0].at;
        p[0].tt=p[0].bt+p[0].wt;
        int i=1;
        while (i<n)
        {
                p[i].ct=p[i-1].ct+p[i].bt;
                p[i].tt=p[i].ct-p[i].at;
                p[i].wt=p[i].tt-p[i].bt;
                i++;
        }
        printf ("\nP.No.\tAT\tBT\tCT\tTAT\tWT");
        i=0;
        int tottt=0;
        int totwt=0;
        while (i<n)
        {
                printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
                tottt+=p[i].tt;
                totwt+=p[i].wt;
                i++;
        }
        float avg1=tottt/n;
        float avg2=totwt/n;
        printf ("\nAverage Turnaround Time: %f", avg1);
        printf ("\nAverage Waiting Time: %f", avg2);
}
                
