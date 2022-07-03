//多重背包问题1
#include<iostream>
using namespace std;
const int N=110;
int f[N][N],w[N],v[N],s[N];
int n,value;
int main()
{
    cin>>n>>value;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i]>>s[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=value;j++)
        {
            f[i][j]=f[i-1][j];
            for(int k=1;k<=s[i]&&k*v[i]<=j;k++)
            {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);
            }
        }
    cout<<f[n][value]<<endl;
    return 0;
}