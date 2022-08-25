//Program to demonstrate the non-premitive sjf algorithm
#include<stdio.h>
#include<string.h>

int main()
{
        int burst[10],pid[10],wait[10],tat[10],start[10],finish[10],i,j,n,totwt,tottat,pos,temp;
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
                        start[i]=0;
                else
                        start[i]=finish[i-1];
                wait[i]=start[i];
                finish[i]=start[i]+burst[i];
                tat[i]=burst[i]+wait[i];
                totwt+=wait[i];
                tottat+=tat[i];
        }
        printf("\nPno\tBurst Time\tWaiting time\tTurnaround time\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t%d\t\t%d\t\t%d",pid[i],burst[i],wait[i],tat[i]);
                printf("\n");
        }
        printf("\nAverage waiting time : %0.2f",(float)totwt/n);
        printf("\nAverage turn around time : %0.2f",(float)tottat/n);
        printf("\n");
        return 0;
}
