#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
pthread_t t1,t2;
sem_t s;
int Numbowl=0;
void *Num_mice()
{
	sem_wait(&s);
	sleep(2);
	printf("\t\tMice is Eating from Numbowl\n");
	sem_post(&s);
	
}
void *Num_cats()
{
	sem_wait(&s);
	sleep(2);
	printf("\t\tCat is Eating from Numbowl\n");
	sem_post(&s);
	
}
int main()
{
	int i,j,h;
	sem_init(&s,0,1);
	int m,c;
	printf("Enter the Number of mic:");
	scanf("%d",&m);
	printf("Enter the Number of Cat:");
	scanf("%d",&c);
	int f=m;
	int k=c;
	while(f!=0&&k!=0)
	{
	 i=pthread_create(&t1,NULL,Num_mice,NULL);
	j=pthread_create(&t2,NULL,Num_cats,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	f--;
	k--;
	}
	if(f!=0)
	{
		for(h=0;h<f;h++)
		{
				int j=pthread_create(&t2,NULL,Num_mice,NULL);
				pthread_join(t2,NULL);
		}
	}
	if(k!=0)
	{
		for(h=0;h<k;h++)
		{
				int j=pthread_create(&t1,NULL,Num_cats,NULL);
				pthread_join(t1,NULL);
		}
	}
	if(i!=0&&j!=0)
	{
		printf("Threads not Created");
	}
	else
	{
		printf("\n\t*****No occurance of starvation*****");
	}
	
}
