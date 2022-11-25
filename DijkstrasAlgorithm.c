#include <stdio.h>
#define infinity 999

void dij(int n,int v,int cost[10][10],int dist[])
{
   int i,u,count,j,flag[10],min;
   for(i=1;i<=n;i++)
    flag[i]=0,dist[i]=cost[v][i];
   count=2;
   while(count<=n)
   {
      min=99;
      for(j=1;j<=n;j++)
       if(dist[j]<min && !flag[j])
        min=dist[j],u=j;
     
      flag[u]=1;
      count++;
     
      for(j=1;j<=n;j++)
       if((dist[u]+cost[u][j]<dist[j]) && !flag[j])
        dist[j]=dist[u]+cost[u][j];
   }
}

void main()
{
   int n,v,i,j,cost[10][10],dist[10];
   printf("n Enter the number of nodes:");
   scanf("%d",&n);
   printf("Enter the cost matrix:");
  
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
       scanf("%d",&cost[i][j]);
       if(cost[i][j]==0)
        cost[i][j]=infinity;
    }
  
   printf(" Enter the source matrix:");
   scanf("%d",&v);
   dij(n,v,cost,dist);
   printf("Shortest path:n");
  
   for(i=1;i<=n;i++)
    if(i!=v)
     printf("%d->%d,cost=%d ",v,i,dist[i]);
}
