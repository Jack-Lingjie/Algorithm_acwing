//291蒙德里安的梦想
#include<iostream>
#include<cstring>
using namespace std;
const int N=1<<11,COL=12;
bool st[N];//是否存在偶数个连续的0
long long f[COL][N];//状态方程
int main()
{
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m,n!=0||m!=0)
    {
        for(int i=0;i<1<<n;i++)//判断0-2^n中每个数是否有连续个偶数
        {
            st[i]=true;
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if((i>>j)&1==1)
                {
                    if(cnt&1)
                    {
                        st[i]=false;
                        break;
                    }else cnt=0;
                }else cnt++;
            }
            if(cnt&1) st[i]=false;
        }
        // for(int i=0;i<1<<n;i++) cout<<st[i]<<endl;
        //状态转移
        memset(f,0,sizeof f);
        f[0][0]=1;//第0列的时候，全部纵向
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<1<<n;j++)
            {
                for(int k=0;k<1<<n;k++)
                {
                    if((k&j)==0&&st[k|j])//不冲突，且存在连续个偶数
                    {
                        f[i][j]+=f[i-1][k];
                    }
                }
            }
        }
        cout<<f[m][0]<<endl;
    }
}