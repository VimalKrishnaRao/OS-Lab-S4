#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int i, j, k, n, m, sum = 0, x, y, h;
    printf("Enter the size of disk: ");
    scanf("%d", &m);
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the requests:\n");

    // Creating an array of size n
    int *a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) 
    {
        if (a[i] > m) 
        {
            printf("Error, Unknown position %d\n", a[i]);
            free(a);
            return 0;
        }
    }

    printf("Enter the head position: ");
    scanf("%d", &h);

    // Head will be at h at the starting
    int temp = h;
    printf("%d", temp);
    for (i = 0; i < n; i++) 
    {
        printf(" -> %d ", a[i]);
        // Calculating the difference for the head movement
        sum += abs(a[i] - temp);
        // Head is now at the next I/O request
        temp = a[i];
    }
    printf("\n");
    printf("Total head movements = %d\n", sum);

    free(a);
    return 0;
}
