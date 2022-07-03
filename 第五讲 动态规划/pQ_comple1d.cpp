//完全背包问题
//优化
//通过滚动数组优化成1维
#include<iostream>
using namespace std;
const int N=1010;
int f[N],v[N],w[N];
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
            if(j>=v[i]) f[j]=max(f[j],f[j-v[i]]+w[i]);
            else f[j]=f[j];
        }
    cout<<f[value]<<endl;
}