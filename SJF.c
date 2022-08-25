//Program to demonstrate the non-premitive sjf algorithm
#include<stdio.h>
#include<string.h>

int main()
{
        int burst[10],pid[10],wt[10],tt[10],i,j,n,totwt=0,tottat=0,temp;
        totwt=0;
        tottat=0;
        printf("Enter the number of process:");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter the process id and burst time:");
                scanf("%d%d",&pid[i],&burst[i]);
        }
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        if(burst[i]<burst[j])
                        {
                                temp=burst[i];
                                burst[i]=burst[j];
                                burst[j]=temp;

                                temp=pid[i];
                                pid[i]=pid[j];
                                pid[j]=temp;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                if(i==0)
		{
			wt[0]=0;
			tt[i]=burst[i]+wt[i];
		}	

                else
		{
			wt[i]=burst[i-1]+wt[i-1];
			tt[i]=burst[i]+wt[i];
		}
        }

	for(i=0;i<n;i++)
	{
		totwt+=wt[i];
		tottat+=tt[i];
	}

        printf("\nPno\tBurst Time\tWaiting time\tTurnaround time\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t%d\t\t%d\t\t%d",pid[i],burst[i],wt[i],tt[i]);
                printf("\n");
        }
        printf("\nAverage waiting time : %0.2f",(float)totwt/n);
        printf("\nAverage turn around time : %0.2f",(float)tottat/n);
        printf("\n");
        return 0;
}
