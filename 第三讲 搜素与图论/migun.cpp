#include<iostream>
#include<queue>
using namespace std;
const int N = 100;
int graph[N][N], visit[N][N];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			visit[i][j] = -1;
		}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	int x[4] = { 0,0,-1,1 }, y[4] = { -1,1,0,0 };//移动数组
	visit[0][0] = 0;
	while (!q.empty()) {//q不为0时

		auto now = q.front();
		q.pop();
		for (int i = 0; i <= 3; i++)
		{
			int xx = now.first + x[i];
			int yy = now.second + y[i];
			//cout << "xx:" << xx << " yy:" << yy << endl;
			if (xx >= 0 && xx < n && yy >= 0 && yy < m&&graph[xx][yy]==0&&visit[xx][yy]==-1)//是0，且未被访问过
			{
				q.push({ xx,yy });
				visit[xx][yy] = visit[now.first][now.second] + 1;
			}
		}
	}

	cout << visit[n-1][m-1] << endl;
	return 0;
}