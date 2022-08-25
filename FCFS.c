//Program to implement FCFS scheduling algorithm

#include<stdio.h>
int main()
{
	int n,i,j,temp;
	printf("\nEnter the no of processes: ");
	scanf("%d",&n);
	int pid[n], bt[n], at[n], tt[n],i,j,totwt=0,tottat=0, wt[n], tat, awt,start[10], finish[10];
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process id, arrival time and burst time: ");
		scanf("%d%d%d", &pid[i], &at[i], &bt[i]);
	}

	//swapping process according to AT
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{

		if(at[i]<at[j])
		{
			temp=at[i];
			at[i]=at[j];
			at[j]=temp;

			temp=pid[i];
			pid[i]=pid[j];
			pid[j]=temp;

			temp=bt[i];
			bt[i]=bt[j];
			bt[j]=temp;

		}
	
		}
	}

	//calculate WT
	
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			wt[0]=at[0];
			tt[i]=bt[i]+wt[i];
		}
		else
		{

		wt[i]=bt[i-1]+wt[i-1];
		tt[i]=bt[i]+wt[i];
		}
	}
	for(i=0;i<n;i++)
	{
		totwt+=wt[i];
		tottat+=tt[i];
	}

	awt=totwt/n;
	tat=tottat/n;

/*	for(i=0;i<n;i++)
	{
		if(i==0)
			start[i]=at[i];
		else
		{
			start[i]=finish[i-1];
		wt[i]=start[i]-at[i];
		finish[i]=start[i]+bt[i];
		tt[i]=finish[i]-at[i];
		totwt+=wt[i];
		tottat+=tt[i];
	}*/

		totwt=totwt/n;
		tottat=tottat/n;
	}
		

	printf("\nPID\tAT\tBT\tWT\tTAT");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],wt[i],tt[i]);

	}

	printf("\nAvreage waiting time: %d",awt );

	printf("\nAverage turnaround time: %d", tat);
	printf("\n");
return 0;
}


