#include<iostream>
using namespace std;
const int N=1010;
int f[N];
int n,m,v[N],w[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)//从高位往低位算起
        {
            if(j>=v[i]) f[j]=max(f[j],f[j-v[i]]+w[i]);
            else f[j]=f[j];
        }
    cout<<f[m];
    return 0;
}