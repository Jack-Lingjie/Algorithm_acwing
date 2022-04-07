#include<iostream>
//#include<algorithm>
using namespace std;
const int N = 100010, M = 500010;
int num[N], son[M][2],id=0;
void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int t = x >> i & 1;
		if (!son[p][t]) son[p][t] = ++id;
		p = son[p][t];
	}
}
int query(int x)
{
	int p = 0;
	int res = 0;
	for (int i = 30; i >= 0; i--)
	{
		int t = x >> i & 1;
		if (son[p][!t])//存在另一个分支
		{
			res += 1 << i;
			//res = res + 1;
			p = son[p][!t];
		}
		else {
			//res =res<<1;
			//res = res + 1;
			p = son[p][t];
		}
		// cout << res << " ";
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		insert(num[i]);
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res = max(res, query(num[i]));
		// cout << res << endl;
	}
	cout << res << endl;
}