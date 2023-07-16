#include <stdio.h>

void FIFO(int prs[], int n, int frame);

void FIFO(int prs[], int n, int frame) 
{
    int pagefault = 0, hit = 0, k = 0, i, j, s, flag = 0;
    int temp[frame];
    printf("\nValues\t");

    for (i = 1; i <= frame; i++)
        printf("Frame%d\t", i);

    printf("\n");
    for (i = 0; i < frame; i++) 
    {
        temp[i] = -1;
    }

    for (i = 0; i < n; i++) 
    {
        s = 0;
        printf("\n%d =>\t", prs[i]);
        for (j = 0; j < frame; j++) 
        {
            if (temp[j] == prs[i])
                s = 1;
        }
        if (s == 0) 
        {
            temp[k] = prs[i];
            k = (k + 1) % frame;
            pagefault++;
            for (j = 0; j < frame; j++) 
            {
                if (temp[j] != -1)
                    printf("%d\t", temp[j]);
            }
        } 
        else 
        {
            printf("\tHit!!!");
        }
    }
    printf("\nTotal Page Faults: %d\n", pagefault);
}

int main() 
{
    int n, i, frame;

    printf("Enter the Length of sequence: ");
    scanf("%d", &n);

    int prs[n];
    printf("Enter the Sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &prs[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &frame);

    FIFO(prs, n, frame);

    return 0;
}
