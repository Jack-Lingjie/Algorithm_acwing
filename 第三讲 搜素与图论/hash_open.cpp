//开放寻址法
#include<iostream>
#include<cstring>
using namespace std;
const int N=200010,mod=200003;
const int INF=0x3f3f3f3f;
int h[N];
void insert(int x)
{
    int t=(x%mod+mod)%mod;
    while(h[t]!=INF)
    {
        t++;
        t%=mod;
    }
    h[t]=x;
}
bool find(int x)
{
    int t=(x%mod+mod)%mod;
    while(h[t]!=INF)
    {
        if(h[t]==x) return true;
        t++;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    memset(h,0x3f,sizeof h);
    for(int i=0;i<n;i++)
    {
        char op;
        int x;
        cin>>op;
        cin>>x;
        if(op=='I')
        {
            insert(x);
        }else {
            if(find(x)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}