//843 n皇后
#include<iostream>
using namespace std;
const int N=20;
int row[N],col[N],diag[N],udiag[N];
int path[N],st[N];
int n;
void dfs(int idx)
{
	if(idx==n)//达到根结点时
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(path[i]==j) cout<<"Q";
				else cout<<".";
			}
			cout<<endl;
		}	
		cout<<endl;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!col[i]&&!diag[idx+i]&&!udiag[idx-i+n])//列，对角线，行上均为被访问
		{
			col[i]=diag[idx+i]=udiag[idx-i+n]=1;//标记为1
			path[idx]=i;
			idx++;
			dfs(idx);
			idx--;
			col[i]=diag[idx+i]=udiag[idx-i+n]=0;
		}
	}
}
int main()
{
	cin>>n;
	dfs(0);
	return 0;
}