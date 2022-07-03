//编辑距离
#include<iostream>
using namespace std;
const int N=1010;
int f[N][N];
int main()
{
    int n,m;
    string a,b;
    cin>>n>>a>>m>>b;
    a=" "+a;
    b=" "+b;
    //容忘记初始化
    for(int i=0;i<=n;i++) f[i][0]=i;
    for(int j=0;j<=m;j++) f[0][j]=j;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j]=min(f[i-1][j],f[i][j-1])+1;
            if(a[i]==b[j]) f[i][j]=min(f[i-1][j-1],f[i][j]);
            else f[i][j]=min(f[i-1][j-1]+1,f[i][j]);
        }
    cout<<f[n][m]<<endl;
    return 0;
}