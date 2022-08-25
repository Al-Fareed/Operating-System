
#include<stdio.h>
#include<string.h>
int main()
{
	int pid[10],t[10];
	int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,j,n,temp;
	int totwt=0,tottat=0;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
        {
		printf("Enter the Process Number, Arrival Time and Burst Time : ");
		scanf("%d%d%d",&pid[i],&arr[i],&bur[i]);
	}
	for(i=1; i<=n; i++)
	{
		 for(j=1; j<=n; j++)
		 {
			 if(arr[j]<arr[i])
			 {
				temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                
                temp=bur[i];
                bur[i]=bur[j];
                bur[j]=temp;
                
                temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
			 }
		 }
	for(i=0; i<n; i++)
	{
		if(i==0)
		{
		star[i]=arr[i];
		finish[i]=bur[i];
		wt[i]=arr[i];
		tat[i]=bur[i]+wt[i];
		}
		else
		{
		finish[i]=bur[i];
		star[i]=finish[i-1];
		wt[i]=bur[i-1]+wt[i-1];
		finish[i]=star[i]+bur[i];
		tat[i]=bur[i]+wt[i];
			
	}
	totwt+=wt[i];
		tottat+=tat[i];
	}
	printf("\nPNo.\tAT\tBT\tWT\tTT");
	for(i=0; i<n; i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d",pid[i],arr[i],bur[i],wt[i],tat[i]);
	
	}
	printf("\nAverage Waiting time:%0.2f",(float)totwt/n);
	printf("\nAverage Turn Around Time:%0.2f",(float)tottat/n);
	printf("\n");
	return 0;
}
}	
