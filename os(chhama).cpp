#include<stdio.h>
int main()
{
	int a,b,k,m,n,p[20],avgt=0,avgta=0,t=0,wtavg=0;
	printf("enter the no of process\n");
	scanf("%d",&n);
	int bt[n];
	int wt[n];
	int tat[n];
	int at[n];
	printf("choose 1 for FCFS and 2 for SJF");
	scanf("%d",&a);
	
	 		for(int i=0;i<n;i++)
	{
		 printf("enter the Burst time for p[%d]:",i+1);
		 scanf("%d",&bt[i]);
		  printf("enter the Arrival time for p[%d]:",i+1);
		 scanf("%d",&at[i]);
		 
	}
	if(a==1)
	{

	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=0;
		for(int j=0;j<i;j++)
		wt[i]+=bt[j];
	}
	printf("Arrival Time\t\tWaiting Time\t\tTurn Around Time\n");
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avgt+=wt[i];
		avgta+=tat[i];
		printf("%d\t\t%d\t\t%d\n",bt[i],wt[i],tat[i]);
	}
	printf("\nAverage Waiting time:%d\n",avgt/n);
	printf("\nAverage turnaround time:%d",avgta/n);
	}
	else if(a==2)
	{
		int temp;
		for(int i=0;i<n;i++)
		{
			int pos=i;
			for(int j=i+1;j<n;j++)
			{
				if(bt[j]<bt[pos]);
				pos=j;
			}
			temp=bt[i];
			bt[i]=bt[pos];
			bt[pos]=temp;
			
			temp=p[i];
			p[i]=p[pos];
			p[pos]=temp;
		}
		wt[0]=0;
		for(int i=1;i<n;i++)
		{
			wt[i]=0;
			for(int j=0;j<i;j++)
			{
				wt[i]+=bt[j];
				t+=wt[i];
			}
			
		}
		wtavg=(float)t/n;
		t=0;
		printf("\nprocess\t\t burst time\twaiting time\t\t turnaround time\n");
		for(int i=0;i<n;i++)
		{
			tat[i]=bt[i]+wt[i];
			t+=tat[i];
			printf("p[%d]\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
			
		}
		avgta=(float)t/n;
		printf("average turnaround time:%d",avgta/n);
	}
	else 
	{
		printf("match not found");
	}
}
