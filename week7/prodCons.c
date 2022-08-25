//Program to simulate producer consumer using semaphore
#include<stdio.h>
#include<stdlib.h>
 
int mutex=1,full=0,empty,x=1;
 
int main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("Enter size of the Buffer:");
    scanf("%d",&empty);
    while(1)
    {
	    printf("\nOption:\n1.Producer\n2.Consumer\n3.Exit\n");
	    printf("Enter your choice:");
	    scanf("%d",&n);
	    switch(n)
	    {
		    case 1:if((mutex==1)&&(empty!=0))
				   producer();
			   else
				   printf("Buffer is Full\n");
			   break;
		    case 2: if((mutex==1)&&(full!=0))
				   consumer();
			    else
			    	   printf("Buffer is Empty\n");
			    break;
		     case 3:exit(0);
		     		break;

		}	}
    return 0;
	}
	int wait(int s)
	{
		return(--s);
	}
	int signal(int s)
	{
		return(++s);
	}
	void producer()
	{
		mutex=wait(mutex);
		full=signal(full);
		empty=wait(empty);
		printf("\nProducer Produced an item %d",x);
		x++;
		mutex=signal(mutex);
	}
	void consumer()
	{
		mutex=wait(mutex);
		full=wait(full);
		empty=signal(empty);
		x--;
		printf("\nConsumer consumed an item %d",x);
		mutex=signal(mutex);
	}





