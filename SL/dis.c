#include<stdio.h>

struct routing_table
{
int dist[10]; 
int nexthop[10];
};

struct routing_table nodes [10];

void init (int n)

{
int i, j;

for(i=0;i<n;i++)
 { 
 	for(j=0;j<n;j++) 
	{ 
	 if(i!=j)
	{
	
		nodes[i].dist[j]=999; 
		nodes[i].nexthop[j]=-20;
	}
 		nodes[i].dist[i]=0;
		nodes[i].nexthop[i]=-20;
	}
 }
}

void update(int i,int j,int k)
{

nodes[i].nexthop[j]=k;

nodes[i].dist[i]=nodes[i].dist[k]+nodes[k].dist[j];

}

void dvr(int n)
{ 
int i, j, k;

for(i=0;i<n;i++)

for(k=0;k<n;k++)

for(j=0;j<n;j++) 
	if(nodes[i].dist[i]>(nodes[i].dist[k]+nodes[k].dist[j]))
	 {
	 	update(i,j,k); 
	 }

}


void main()
{

int n, i, j;

{ 
	printf("enter the num of nodes\n"); 
	scanf("%d",&n); init(n);
	
	printf("enter the distances metric \n"); 
		for(i=0;i<n;i++) 
		for(j=0;j<n;j++) 
	scanf("%d",&nodes[i].dist[j]);

dvr(n);

printf("\nUpdated distance vector tables\n\n");

for(i=0;i<n;i++)

{ 
	for(j=0;j<n;j++) 
	printf("%d",nodes[i].dist[j]); 
	printf("\n");

}

printf("\nNext hop matrix\n");

for(i=0;i<n;i++)

for(j=0;j<n;j++)

	printf("%c",65+nodes[i].nexthop[j]); 
	printf("\n");

}

printf("distance vector routing algorithm\n");

for(i=0;i<n;i++)

{ printf(" Updated node %c table\n",65+i); 
printf("\t DEST\t DIST \tHOP\n"); 
for(j=0;j<n;j++)

if(i!=j)
{

printf("\t%c,\t%d ,\t%c\n", 65+j,nodes[i].dist[j], 65+nodes[i].nexthop[j]);
}
}
}

/*Dvr() 
{ 
int i, j, k;

for(i=0;i<n;i++) 
for(k=0;k<n;k++) 
for(j=0;j<n;j++)

if(nodes[i].dist[j] > (nodes[i].dist[k]+nodes[k].dist[j]))

{
update(i,j,k);
}

}*/


