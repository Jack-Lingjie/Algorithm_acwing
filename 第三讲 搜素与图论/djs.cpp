#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 600;
int graph[N][N];
int dist[N];
bool st[N];
const int INF = 1e6;
int djis(int n)
{
	dist[1] = 0;
	for (int i = 0; i < n; i++)
	{
		int j = -1;
		for (int t = 1; t <= n; t++)//找到当前离原点最近的点
		{
			if (!st[t] && j == -1 || dist[t] < dist[j])
				j = t;
		}
		//松弛操作
		for (int t = 1; t <= n; t++)
		{
			dist[t] = min(dist[t],dist[j]+graph[j][t]);
		}
		st[j] = true;//标记
	}
	if (dist[n] == INF) return -1;
	return dist[n];
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			graph[i][j] = INF;
	}
	for (int i = 1; i <= n; i++) dist[i] = INF;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (x == y) continue;
		graph[x][y] = min(graph[x][y], z);//消除重边
	}
	int min = djis(n);
	cout << min << endl;

}