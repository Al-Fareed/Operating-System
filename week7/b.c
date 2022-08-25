#include<stdio.h>
int n,r,alloc[10][10],ar[10],max[10][10],need[10][10],i,j;
void get();
void show();
void cal();
int main()
{
	get();
	show();
	cal();
	printf("--------------------------------------------------\n");
	return 0;
	printf("\n");
}
void get() 
{
	printf("Enter number of process:");
	scanf("%d",&n);
	printf("Enter number of resourcs:");
	scanf("%d",&r);
	printf("Entered Allocated resources:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter number of Available resources:");
		 for(j=1;j<=r;j++)
	        {
			scanf("%d",&ar[j]);
		}
		 
	printf("Enter maximum resource allocated for processes:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
}
void show()
{
	printf("--------------------------------------------------\n");
	printf("Pno\tAlloc\tMax\tAvail\tNeed\n");
	for(i=1;i<=n;i++)
	{

		printf("P%d\t",i);
		for(j=1;j<=r;j++)
		{
			printf("%d ",alloc[i][j]);
		}
		printf("\t");
		for(j=1;j<=r;j++)
		{
			printf("%d ",max[i][j]);
		}
		printf("\t");
			if(i==1)
			{
				for(j=1;j<=r;j++)
				{
					printf("%d ",ar[j]);
				}		
			}
		printf("\t");
		for(j=1;j<=r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
}
void cal()
{
	int finish[100],need[100][100],flag=1,k,c1=0;
	int safe[100];
	int i,j;
	for(i=0;i<n;i++)
	{
		finish[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{	
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("\n");
	while(flag)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			int c=0;
			for(j=0;j<r;j++)
			{
				if((finish[i]==0)&&(need[i][j]<=ar[j]))
				{
					c++;
					if(c==r)
					{
						for(k=0;k<r;k++)
						{
							ar[k]+=alloc[i][j];
							finish[i]=1;
							flag=1;
						}
						printf(" P%d->",i);
						if(finish[i]==1)
						{
							i=n;
						}
					}	
				}
			}	
		}	
	}
	for(i=0;i<n;i++)
	{
		if(finish[i]==1)
		{
			c1++;
		}
		else
		{	
			printf(" P%d->",i);
		}

	}	
	if(c1==n)
	{
		printf("\n The system is in safe state\n");
	}
	else
	{
		printf("\n Process are in dead lock\n");
		printf("\n System is in unsafe state\n");
	}
}
