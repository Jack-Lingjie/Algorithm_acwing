//完全背包问题
//优化
#include<iostream>
using namespace std;
const int N=1010;
int f[N][N],v[N],w[N];
int n,value;
int main()
{
    cin>>n>>value;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=value;j++)
        {
            // f[i][j]=f[i-1][j];
            
            // for(int k=0;k*v[i]<=j;k++)
            // {
                // f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);
            // }
            if(j>=v[i]) f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i]);
            else f[i][j]=f[i-1][j];
        }
    cout<<f[n][value]<<endl;
}