#include<iostream>
#include<cstring>
using namespace std;
const int N=200010;
int e[N],ne[N],h[N],color[N],idx=0;
int n,m;
void add(int x,int y)
{
    e[idx]=y;
    ne[idx]=h[x];
    h[x]=idx++;
}
bool dfs(int x,int c)
{
    color[x]=c;
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int t=e[i];
        if(!color[t])//未被染色
        {
            if(!dfs(t,3-c))//需要判别子dfs返回值是否是false
            {
                return false;
            }
        }else{
                    // cout<<"node"<<t<<" "<<color[t]<<" x:"<<x<<": "<<c<<" "<<(color[t]==c)<<endl;

            if(color[t]==c)
            {
                return false;
            } 
        }
    }
    return true;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u); 
    }
    //染色
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))
            {
                flag=false;
                break;
            }
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}