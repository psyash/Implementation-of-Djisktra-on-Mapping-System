#include<stdio.h>
#include<time.h>

clock_t start, end;

double cpu_time_used;

void djisktra(int nodes[9][9],int n,int source,int des, char cities[9][30]);

int main()
{
int i,j, sor, n, m, k,soc,des,temp;
n=8;
char cities[8][30]={"Dehradun","Ponta Sahib","Yamunanagar","Saharanpur", "Panipat","Muzzafanagar", "karnal", "delhi"} ;

int Adj[9][9]={{0,47,0,95,0,0,0,0},{47,0,61,0,0,0,0,0},{0,61,0,39,0,0,67,0},{95,0,0,0,0,66,92,0},{0,0,0,0,0,0,36,87},{0,0,0,66,0,0,0,150},{0,0,67,0,36,0,0,0},{0,0,0,0,87,150,0,0}};

a:
printf("enter source city?\n0.Dehradun\n1.Ponta Sahib\n2.Yamunanagar\n3.Saharanpur\n4.Panipat\n5.Muzzafanagar\n6.karnal\n7.delhi\n");
scanf("%d",&soc);

printf("enter destination city?\n0.Dehradun\n1.Ponta Sahib\n2.Yamunanagar\n3.Saharanpur\n4.Panipat\n5.Muzzafanagar\n6.karnal\n7.delhi\n");
scanf("%d",&des);

if(soc==des)
{printf("Source and Destination cannot be same, please try again\n");
goto a;}

if(soc>des)
{temp=soc;
soc=des;
des=temp;
}

djisktra(Adj, n, soc,des,cities);
return 0;
}

void djisktra(int nodes[9][9],int n,int source,int des, char cities[9][30])
{
start=clock();
int cost[9][9],dist[9], pred[9];
int visited[8],count,mindistance,next, i,j;

for(i=0;i<=n;i++)
{
for(j=0;j<=n;j++)
{
if(nodes[i][j]==0)
{cost[i][j]=10000;}
else
{cost[i][j]=nodes[i][j];}
}
}

for(i=0; i<=7;i++)
{ dist[i]=cost[source][i];
pred[i]=source;
visited[i]=0;
}

dist[source]=0;
visited[source]=1;
count=1;

while(count<=7)
{
mindistance=10000;
for(i=0;i<=7;i++)
{
if(dist[i]<mindistance &&!visited[i])
{
mindistance=dist[i];
next=i;
}
}
visited[next]=1;

for(i=1;i<=7; i++)
{
if(!visited[i])
{if(mindistance+cost[next][i]<dist[i])
 {
  dist[i]=mindistance+cost[next][i];
  pred[i]=next;
 }
}
}
count++;
}

end=clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

printf("distance of %s to %s or %s to %s is=%d",cities[source], cities[des],cities[des], cities[source],dist[des]);

for(i=0;i<=7;i++)

{if(i!=source)
{
printf("\ndistance of  %s=%d",cities[i],dist[i]);
printf("\nPath=%s",cities[i]);
j=i;

do
{j=pred[j];
printf("<-%s",cities[j]);
 }while(j!=source);
printf("\n"); }
}
printf("\ntotal time used is %f", cpu_time_used);
}
