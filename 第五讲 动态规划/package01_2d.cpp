//01背包问题
//使用2维数组
#include<iostream>
using namespace std;
int n,m;
const int N=1010;
int f[N][N],v[N],w[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(j>=v[i]) 
            f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
        else f[i][j]=f[i-1][j];
    }
    cout<<f[n][m]<<endl;
    return 0;
}