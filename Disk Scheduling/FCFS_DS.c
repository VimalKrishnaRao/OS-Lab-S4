#include <stdio.h>
#include <stdlib.h>

void FCFS(int[], int, int);

void main()
{
    int n, i, intialhead;

    printf("\n<------- FCFS Disk Scheduling Algorithm ------->\n\n");
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("Enter the initial head: ");
    scanf("%d", &intialhead);

    FCFS(req, intialhead, n);
}

void FCFS(int p[], int intial, int n)
{
    int i, total = 0;
    for (i = 0; i < n; i++)
    {
        total += abs(p[i] - intial);
        intial = p[i];
    }
    printf("\n==> Total head movement = %d\n", total);
}
