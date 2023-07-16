#include <stdio.h>

void LFU(int prs[], int n, int frame);
void print(int frames[], int f);

void LFU(int pr[], int n, int f) 
{
    int pagefault = 0, i, j, freq[n], minimum, index, flag = 0, frames[n], pos = 0;
    printf("\nValues\t");

    for (i = 1; i <= f; i++)
        printf("Frame%d\t", i);

    printf("\n");
    for (i = 0; i < n; i++)
        frames[i] = -1;
    for (i = 0; i < n; i++) {
        printf("%d =>\t", pr[i]);
        flag = 0;
        for (j = 0; j < n; j++) 
        {
            if (pr[i] == frames[j]) 
            {
                flag = 1;
                freq[j]++;
                printf("\tHit!!!\n");
                break;
            }
        }
        if (flag == 0 && pagefault < f) 
        {
            frames[pos] = pr[i];
            freq[pos] = 1;
            pos = (pos + 1) % f;
            pagefault++;
            print(frames, f);
        } 
        else if (flag == 0) 
        {
            index = 0;
            minimum = freq[0];
            for (j = 1; j < f; j++) 
            {
                if (freq[j] < minimum) 
                {
                    index = j;
                    minimum = freq[j];
                }
            }
            frames[index] = pr[i];
            freq[index] = 1;
            pagefault++;
            print(frames, f);
        }
    }
    printf("Total Page Faults: %d\n", pagefault);
}

void print(int frames[], int f) 
{
    int j;
    for (j = 0; j < f; j++) 
    {
        if (frames[j] != -1)
            printf("%d\t", frames[j]);
        else
            printf("\t");
    }
    printf("\n");
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

    LFU(prs, n, frame);

    return 0;
}
