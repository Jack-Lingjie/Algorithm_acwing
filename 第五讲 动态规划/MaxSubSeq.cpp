#include<iostream>
using namespace std;
const int N=1010;
int f[N][N];
int main()
{
    string a,b;
    int n,m;
    cin>>n>>m;
    cin>>a>>b;
    a=" "+a;//使index从1开始
    b=" "+b;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j]) 
            f[i][j]=f[i-1][j-1]+1;
        else 
            f[i][j]=max(f[i][j-1],f[i-1][j]);
    }
    cout<<f[n][m]<<endl;
    return 0;
}