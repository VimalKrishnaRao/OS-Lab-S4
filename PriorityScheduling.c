#include<stdio.h>
void swap (int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}
int main()
{
        int i, j, n, cmpt;
        float twt = 0, ttat = 0;
        printf ("\nEnter how many processes: ");
        scanf ("%d", &n);
        int a[n][6];
        printf ("\n Enter arrival time, burst time and priority of each process:");
        for (i=0; i<n; i++)
        {
                
                printf ("\nProcess ID: ");
                scanf ("%d", &a[i][0]);
                printf ("\nA.T of process %d: ", a[i][0]);
                scanf ("%d", &a[i][1]);
                printf ("\nB.T of process %d: ", a[i][0]);
                scanf ("%d", &a[i][2]);
                printf ("\nPriority of process %d: ", a[i][0]);
                scanf ("%d", &a[i][5]);
        }
        for (i=0; i<n; i++)
        {
            for (j=0; j<n-i-1; j++)
            {
                if (a[j][1]>a[j+1][1])
                {
                        swap (&a[j][0], &a[j+1][0]);    
                        swap (&a[j][1], &a[j+1][1]); 
                        swap (&a[j][2], &a[j+1][2]); 
                        swap (&a[j][5], &a[j+1][5]);
                }
            }
        }
        a[0][3] = a[0][1];
        a[0][4] = a[0][2] - a[0][1];
        cmpt = a[0][4];
        twt+=a[0][3];
        ttat+=a[0][4];
        for (i=1; i<n; i++)
        {
                int min = a[i][5]; 
                for (j=i+1; j<n; j++)
                {
                        if (min>a[j][5] && a[j][1]<=cmpt)
                        {
                                min = a[j][5];
                                swap (&a[i][0], &a[j][0]);
                                swap (&a[i][1], &a[j][1]);
                                swap (&a[i][2], &a[j][2]);
                                swap (&a[i][5], &a[j][5]);
                        }
                }
                a[i][3] = cmpt - a[i][1];
                twt+=a[i][3];
                cmpt+=a[i][2];
                a[i][4] = cmpt - a[i][1];
                ttat+=a[i][4];
        }
        printf("\nP.No.\tAT\tBT\tP.R\tTAT\tWT");
        for (i=0; i<n; i++)
        {
            printf("\n%d\t%d\t%d\t%d\t%d\t%d", a[i][0], a[i][1], a[i][2], a[i][5], a[i][4], a[i][3]);
        }
        printf ("\nAverage Turnaround time = %f", ttat/n);
        printf ("\nAverage Waiting time = %f", twt/n);
        return 0;
}
                
                
