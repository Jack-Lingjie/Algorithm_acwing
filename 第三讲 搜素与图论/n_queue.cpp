#include<iostream>
using namespace std;
const int N = 20;
char path[N][N];
int col[N], diag[N], udiag[N],n;
void DFS(int now)
{
	if (now == n)//遍历结束
	{
		for (int i = 0; i < n; i++)
		{
			//cout << col[i] << endl;
			for (int j = 0; j < n; j++)
			{
				if (path[i][j] == 'Q') cout << 'Q';
				else cout << ".";
				//if (j == col[i]) cout << 'Q';
				//else cout << '.';
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!col[i] && !diag[now + i] && !udiag[i - now + n])//可以放置皇后
		{
			col[i] = diag[now + i] = udiag[i - now + n] = 1;
			path[now][i] = 'Q';
			DFS(now + 1);
			path[now][i] = '.';
			col[i] = diag[now + i] = udiag[i - now + n] = 0;

		}
	}
}

int main()
{
	//int n;
	cin >> n;
	DFS(0);

}