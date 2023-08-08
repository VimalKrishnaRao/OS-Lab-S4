#include<stdio.h>
void main()
{
    int ninst, np;
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the number of resources : ");
    scanf("%d", &ninst);
  printf("\n");
    int totres[ninst];
    for(int i=0;i<ninst;i++)
      {
      printf("Total no of instances of Resource R%d: ",i+1);
      scanf("%d",&totres[i]);
      }

    // Inputting Allocation & Max Matrix
    int allocmat[np][ninst], Available[ninst],need[np][ninst];;

    printf("\nInput the Allocation Matrix:\n");
    for(int i = 0; i < np; i++)
    {
        for(int j = 0; j < ninst; j++)
        {
            scanf("%d", &allocmat[i][j]);
        }
    }

    printf("\nInput the need Matrix:\n");
    for(int i = 0; i < np; i++)
    {
        for(int j = 0; j < ninst; j++)
        {
            scanf("%d", &need[i][j]);
        }
    }

  //Calculating available array
  for(int j=0;j<ninst;j++)
    {
      Available[j]=totres[j];
      for(int i = 0; i< np; i++)
          Available[j]-=allocmat[i][j];
    }
   
  
    int flag, completed[np], safeseq[np],checker=0, index = 0;
    for(int i = 0; i < np; i++)
    {
        completed[i] = 0;
    }

    for(int c = 0; c < np; c++)
    {
        for(int i = 0; i < np; i++)
        {
            if(completed[i] == 0)
            {
                flag = 0;
                for(int j = 0; j < ninst; j++)
                {
                    if(need[i][j] > Available[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    safeseq[index++] = i;
                    for(int k = 0; k < ninst; k++)
                    {
                        Available[k] += allocmat[i][k];
                    }
                    completed[i] = 1;
                  checker++;
                }
            }
        }
    }
 if(checker==np){
    printf("\nNo Deadloack\nSafe Sequence is:\n\t");
    for(int i = 0; i < np - 1; i++)
    {
        printf("P%d -> ", safeseq[i]);
    }
    printf("P%d\n", safeseq[np - 1]);
 }
  else{printf("\nDeadlock detected");}
}
