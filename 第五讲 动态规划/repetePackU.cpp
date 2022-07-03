//多重背包问题
//使用二进制优化
#include<iostream>
using namespace std;
const int N=12010,M=2010;
int s[N],v[N],w[N];
int f[M];
int n,value;
int main()
{
    cin>>n>>value;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int k=1;
        while(k<c)
        {
            cnt++;
            v[cnt]=a*k;
            w[cnt]=b*k;
            c-=k;
            k*=2;
        }
        if(c!=0)
        {
            cnt++;
            v[cnt]=a*c;
            w[cnt]=b*c;
        }
    }
    int n=cnt;//转化维01背包问题
    for(int i=1;i<=n;i++)
    for(int j=value;j>=v[i];j--)
    {
        f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
    cout<<f[value]<<endl;
    return 0;
}