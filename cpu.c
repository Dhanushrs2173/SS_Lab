#include<stdio.h>

void fcfs();
void sjf();
void priority();
void robin();

struct scheduling
{
	int at,bt,bttemp,ct,tat,wt,pr,flag;
}p[50];

int n,m,i,j,ch,temp,c;
float avgtat=0.0,avgwt=0.0,totat,towt;

void main()
{
	
	

	do
	{
		printf("----MENU----\n");	
		printf("1.FCFS\n");
		printf("2.SJF\n");
		printf("3.Roundrobin\n");
		printf("4.Priority\n");
		printf("5.Exit\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		printf("\nEnter the no of processes:");
		scanf("%d",&n);
		
		printf("\nEnter the AT and BT:\n");
		for(i=0;i<n;i++)
		{
			printf("AT[""%d""]=",i);
			scanf("%d",&p[i].at);
			printf("BT[""%d""]=",i);
			scanf("%d",&p[i].bt);
			p[i].flag=0;
		}
	

		switch(ch)
		{
			case 1:	fcfs();
				break;
			
			case 2:	sjf();
				break;
			
			case 3:	priority();
				break;
			
			case 4: robin();
				break;			
			
			
			default: printf("Invalid choice:");
		}printf("\n Do you want to continue? \n 1)Yes,2)No ");
 		scanf("%d",&c);
 	}while(c==1);
	
}


void fcfs()
{
	
	p[0].wt=0;
	p[0].ct=p[i].bt;
	
	for(i=0;i<n;i++)
	{
		p[i].ct=p[i-1].ct+p[i].bt;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		totat+=p[i].tat;
		towt+=p[i].wt;
	}\
	printf("PNo\tAT\tBT\tCT\tTAT\tWT\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	
	avgtat=totat/n;
	avgwt=towt/n;
	printf("Average TAT=%f \n",avgtat);	
	printf("Average WT=%f \n",avgwt);
}

void sjf()
{
	int b[50];
	int k=0;
	int c=0;
	int m=n;
	
	for(i=0;i<n;i++)
	{
		printf("\nAT[%d]",i);
		scanf("%d",&p[i].at);
		printf("\nBT[%d]",i);
		scanf("%d",&p[i].bt);
	}
	
	while(m>0)
	{
		for(i=0;i<n;i++)
		{
			if(p[i].at=c && p[i].flag==0)
			{
				b[k]=i;
				k++;
			}
		}
		int x=b[0];
		int y;
		for(i=1;i<k;i++)
		{
			y=b[i];
			if(p[x].bt>p[y].bt)
			{
				temp=x;
				x=y;
				y=temp;
			}
		}
		p[x].ct=c+p[x].bt;
		p[x].tat=p[x].ct-p[x].at;
		p[x].wt=p[x].tat-p[x].bt;
		p[x].flag=1;
		c=p[x].ct;
		totat+=p[x].tat;
		towt+=p[x].wt;
		m--;
	}
	
	printf("PNo\tAT\tBT\tCT\tTAT\tWT\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	
	avgtat=totat/n;
	avgwt=towt/n;
	printf("Average TAT=%f \n",avgtat);	
	printf("Average WT=%f \n",avgwt);
}

void priority()
{
	int c=0;
	
	
	for(i=0;i<n;i++)
	{
		printf("PRno[""%d""]=",i);
		scanf("%d",&p[i].pr);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].pr>p[j].pr)
			{
				int temp1=p[i].bt;
				p[i].bt=p[j].bt;	
	 			p[j].bt=temp1;
	 			
	 			int temp2=p[i].pr;
				p[i].pr=p[j].pr;	
	 			p[j].pr=temp2;
	 		}
	 	}
	 }
	 p[0].wt=0;
	 p[0].ct=p[i].bt;
	 
	 for(i=0;i<n;i++)	
	 {
	 	p[i].ct=p[i-1].ct+p[i].bt;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		totat+=p[i].tat;
		towt+=p[i].wt;
	}
	
	printf("PNo\tAT\tPN\tBT\tCT\tTAT\tWT\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p[i].pr,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	
	avgtat=totat/n;
	avgwt=towt/n;
	printf("Average TAT=%f \n",avgtat);	
	printf("Average WT=%f \n",avgwt);
		
	 	
}

void robin()
{

	int q,c=0,tt=0;
	int m=n;
	
	
	printf("Enter the time Quanta:");
	scanf("%d",&q);
	
	while(tt>0)
	{
		for(i=0;i<n;i++)
		{
			if(p[i].at<=c && p[i].flag==0)
			{
				if(p[i].bttemp<=q)
				{
					p[i].ct=c+p[i].bttemp;
					c=p[i].ct;
					p[i].flag=1;
					tt=tt-p[i].bttemp;
					p[i].tat=p[i].ct-p[i].at;
					p[i].wt=p[i].tat-p[i].bt;
					totat+=p[i].tat;
					towt+=p[i].wt;
				}
				else if(p[i].bttemp>q)
				{
					p[i].bttemp-=q;
					tt=tt-q;
					c+=q;
				}
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	
	avgtat=totat/n;
	avgwt=towt/n;
	printf("Average TAT=%f \n",avgtat);	
	printf("Average WT=%f \n",avgwt);
}	
		
	
