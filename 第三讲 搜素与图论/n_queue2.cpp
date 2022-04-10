#include<iostream>
using namespace std;
const int N = 20;
char path[N][N];
int row[N], col[N], diag[N], udiag[N],n;
void DFS(int x,int y,int q)
{
	//cout << "x: " << x << " y: " << y << " q : " << q << endl;
	//if (q > n) return;
	if (y == n)
	{
		y = 0;
		x++;
	}
	if (x == n && q != n) return;
	if (q == n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << path[i][j];
			cout << endl;
		}
		cout << endl;
	}
	else {

		if (!row[x] && !col[y] && !diag[x + y] && !udiag[y - x + n])//可以放
		{
			row[x] = col[y] = diag[x + y] = udiag[y - x + n] = 1;
			path[x][y] = 'Q';
			//q++;
			DFS(x, y + 1, q+1);
			path[x][y] = '.';
			row[x] = col[y] = diag[x + y] = udiag[y - x + n] = 0;
		}
		path[x][y] = '.';
		DFS(x, y + 1, q);
	}
}
int main()
{
	//int n;
	cin >> n;
	DFS(0,0,0);
	return 0;

}