#include<stdio.h>
#include<iostream>
int main()
{
	int pno,process[10],at[10],wt[10],tat[10],bt[10];
	float avgwt,avgtat;
	int i,j,temp;
	printf("Enter no.of processes:");
	scanf("%d",&pno);
	for(i=0;i<pno;i++)
	{
		printf("Enter Process ID:");
		scanf("%d",&process[i]);
		printf("Enter Process bust time:");
		scanf("%d",&bt[i]);
		printf("Enter Process arrival time:");
		scanf("%d",&at[i]);
		fflush(stdin);
	}
	
	for(i=0;i<pno;i++)
	{
		for(j=i+1;j<pno;j++)
		{
		if(at[i]>at[j])
		{
			temp=at[i];
			at[i]=at[j];
			at[j]=temp;
			
			temp=bt[i];
			bt[i]=bt[j];
		    bt[j]=temp;
			
			temp=process[i];
			process[i]=process[j];
			process[j]=temp;
		}
		}
	}
	
	wt[0]=0;
	for(i=0;i<pno;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]=wt[i]+bt[j];
		}
		wt[i]=wt[i]-at[i];
	}
	printf("\n Process\t|\t Burst Time\t|\tArrival Time\t|\t Waiting Time\t|\t Turn around time");
	for(i=0;i<pno;i++)
	{
		tat[i]=bt[i]+wt[i]+at[i];
		avgwt+=wt[i];
		avgtat+=tat[i];
		printf("\nP[%d]\t|\t %d\t\t|\t%d\t\t|\t %d",process[i],bt[i],at[i],wt[i],tat[i]);
	}
	printf("\n\n Totalturn amount time:%d",tat[pno-1]);
	avgwt/=pno;
	avgtat/=pno;
	printf("\n Average Waiting time: %f",avgwt);
	printf("\n Average turnaround time:%f",avgtat);
	return 0;
}
	
	

		
		
