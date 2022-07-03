//291蒙德里安的梦想
//去掉无效状态
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=1<<11;
bool st[N];//是否存在偶数个连续的0
long long f[12][N];//状态方程
vector<int> v[N];
int main()
{
    int n,m;
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while(cin>>n>>m,n||m)
    {
        for(int i=0;i<1<<n;i++)//判断0-2^n中每个数是否有连续个偶数
        {
            bool is_valid=true;
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if((i>>j)&1)
                {
                    if(cnt&1)
                    {
                        is_valid=false;
                        break;
                    }
                    cnt=0;
                }else cnt++;
            }
            if(cnt&1) is_valid=false;
            st[i]=is_valid;
        }
        
        for(int i=0;i<1<<n;i++)
        {
            v[i].clear();
            for(int j=0;j<1<<n;j++)
            {
                
                if((i&j)==0&&st[i|j])
                {
                    v[i].push_back(j);
                }
            }
        }
        //状态转移
        memset(f,0,sizeof f);
        f[0][0]=1;//第0列的时候，全部纵向
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<1<<n;j++)
            {
                for(auto &k:v[j])
                {
                    f[i][j]+=f[i-1][k];
                }
            }
        }
        cout<<f[m][0]<<endl;
    }
}