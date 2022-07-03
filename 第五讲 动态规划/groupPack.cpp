//分组背包问题
#include<iostream>
using namespace std;
const int N=110;
int v[N][N],w[N][N],s[N],f[N];
int n,value;
int main()
{   
    cin>>n>>value;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=1;j<=s[i];j++)
        {
            cin>>v[i][j]>>w[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    for(int j=value;j>=1;j--)
    {
        for(int k=1;k<=s[i];k++)
        if(j>=v[i][k]) f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
    }
    cout<<f[value]<<endl;
    return 0;
}