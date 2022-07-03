//Djistra
#include<iostream>
#include<cstring>
using namespace std;
const int N=510;
int graph[N][N],n,m,st[N],dist[N];
const int INF=10010;
void djstra()
{
	st[1]=1;
	dist[1]=0;
	int t=1;
	int j;
	
	int count=n;
	while(count-->0)
	{
		int min=INF;
		for(int i=1;i<=n;i++)
		{
			if(st[i]==0)
			{
				if(dist[t]+graph[t][i]<dist[i]) dist[i]=dist[t]+graph[t][i];// 先松弛，后比较
				if(dist[i]<min)
				{
					min=dist[i];
					j=i;
				}
			}
		}
		st[j]=1;
		t=j;
	}

	if(dist[n]==INF) cout<<"-1"<<endl;
	else cout<<dist[n]<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{

	 for(int j=1;j<=n;j++)
		{
			graph[i][j]=INF;
		}

	}
	for(int i=1;i<=n;i++) dist[i]=INF;
	for(int i=0;i<m;i++)
	{	
		int x,y,z;
		cin>>x>>y>>z;
		graph[x][y]=min(graph[x][y],z);

	}

	djstra();
	return 0;
}