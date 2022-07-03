#include<iostream>

//844走迷宫
using namespace std;
const int N=110;
int graph[N][N],hh=0,tt=-1,st[N][N],layer[N][N];
int n,m;
pair<int,int> queue[N*N];
void bfs()
{
	queue[++tt]=make_pair(1,1);
	int dx[]{-1,1,0,0};
	int dy[]{0,0,-1,1};
	st[0][0]=1;
	int sum=0;
	while(hh<=tt)//队列不为空
	{
		auto loc=queue[hh++];
		int x,y;
		x=loc.first;
		y=loc.second;
		for(int i=0;i<4;i++)
		{
			if(x+dx[i]>=1&&x+dx[i]<=n&&y+dy[i]>=1&&y+dy[i]<=m&&graph[x+dx[i]][y+dy[i]]==0&&st[x+dx[i]][y+dy[i]]==0)
			{
				queue[++tt]=make_pair(x+dx[i],y+dy[i]);
				st[x+dx[i]][y+dy[i]]=1;
				layer[x+dx[i]][y+dy[i]]=layer[x][y]+1;
			}
		}
		// sum++;
	}
	cout<<layer[n][m]<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>graph[i][j];
	bfs();
	return 0;
}