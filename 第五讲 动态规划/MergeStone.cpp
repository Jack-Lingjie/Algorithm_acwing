//合并石子
#include<iostream>
using namespace std;
const int N=310,INF=0x3f3f3f3f;
int n;
int f[N][N];
int s[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s[i]=s[i-1]+x;
    }
    for(int len=2;len<=n;len++)//区间长度
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int r=i+len-1;
            f[i][r]=INF;
            for(int k=i;k<r;k++)
            {
                f[i][r]=min(f[i][r],f[i][k]+f[k+1][r]+s[r]-s[i-1]);
            }
            // cout<<"i r "<<i<<" "<<r<<" "<<f[i][r]<<endl;
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}