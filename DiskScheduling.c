#include <stdio.h>
#include <stdlib.h>

void FCFS(int[], int, int);
void scanALG(int[], int, int);
void cscanALG(int[], int, int);

void main()
{
    int n, i, intialhead, ch;

    printf("\n<------- Disk Scheduling Algorithm Program ------->\n\n Enter the number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf(" Enter the sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf(" Enter the initial head: ");
    scanf("%d", &intialhead);
    do
    {
        printf("\n----------------------------------------------\n\n1. FCFS\n2. SCAN\n3. C-SCAN\n4. Exit\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("\nFor FCFS Disk Scheduling Algorithm,\n");
            FCFS(req, intialhead, n);
            break;
        }
        case 2:
        {
            printf("\nFor SCAN Disk Scheduling Algorithm,\n");
            scanALG(req, intialhead, n);
            break;
        }
        case 3:
        {
            printf("\nFor C-SCAN Disk Scheduling Algorithm,\n");
            cscanALG(req, intialhead, n);
            break;
        }
        case 4:
            printf("\n<------- Exiting the program ------->\n");
            break;
        default:
            printf("\nInvalid Choice!!!\n");
        }
    } while (ch != 4);
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

void scanALG(int r[], int intial, int n)
{
    int disksize, d, i, j, total = 0;
    printf(" Enter the disk size: ");
    scanf("%d", &disksize);
    printf(" Directions => 1. High\t2. Low\n Enter the head movement direction: ");
    scanf("%d", &d);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (r[j] > r[j + 1])
            {
                int temp;
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }
    int index;
    for (i = 0; i < n; i++)
    {
        if (intial < r[i])
        {
            index = i;
            break;
        }
    }
    if (d == 1)
    {
        for (i = index; i < n; i++)
        {
            total = total + abs(r[i] - intial);
            intial = r[i];
        }
        total = total + abs(disksize - r[i - 1] - 1);
        intial = disksize - 1;
        for (i = index - 1; i >= 0; i--)
        {
            total = total + abs(r[i] - intial);
            intial = r[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            total = total + abs(r[i] - intial);
            intial = r[i];
        }
        total = total + abs(r[i + 1] - 0);
        intial = 0;
        for (i = index; i < n; i++)
        {
            total = total + abs(r[i] - intial);
            intial = r[i];
        }
    }
    printf("==> Total head movement is %d\n", total);
}

void cscanALG(int q[], int intial, int n)
{
    int disksize, d, i, j, total2 = 0;
    printf(" Enter the disk size: ");
    scanf("%d", &disksize);
    printf(" Directions => 1. High\t2. Low\n Enter the head movement direction: ");
    scanf("%d", &d);

    // Sort the req array
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (q[j] > q[j + 1])
            {
                int temp;
                temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }
    // Finding index
    int index;
    for (i = 0; i < n; i++)
    {
        if (intial < q[i])
        {
            index = i;
            break;
        }
    }
    // If high
    if (d == 1)
    {
        for (i = index; i < n; i++)
        {
            total2 = total2 + abs(q[i] - intial);
            intial = q[i];
        }
        // Last movement for max size
        total2 = total2 + abs(disksize - q[i - 1] - 1);
        /* movement max to min disk */
        total2 = total2 + abs(disksize - 1 - 0);
        intial = 0;
        for (i = 0; i < index; i++)
        {
            total2 = total2 + abs(q[i] - intial);
            intial = q[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            total2 = total2 + abs(q[i] - intial);
            intial = q[i];
        }
        // Last movement for min size
        total2 = total2 + abs(q[i + 1] - 0);
        // Movement min to max disk
        total2 = total2 + abs(disksize - 1 - 0);
        intial = disksize - 1;
        for (i = n - 1; i >= index; i--)
        {
            total2 = total2 + abs(q[i] - intial);
            intial = q[i];
        }
    }
    printf("==> Total Head movement = %d\n", total2);
}
