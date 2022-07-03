//spfa判断负环
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100010;
int h[N],e[N],ne[N],w[N],idx;
int dist[N],st[N],cnt[N];
int n,m;
void add(int x,int y,int z)
{
    e[idx]=y;
    w[idx]=z;
    ne[idx]=h[x];
    h[x]=idx++;
}
bool spfa()
{
    queue<int> q;
    // q.push(1);
    // st[q]=1;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        st[i]=1;
    }
    while(q.size())
    {
        int v=q.front();//可能存在不是冲1开始的环
        q.pop();
        st[v]=0;
        for(int i=h[v];i!=-1;i=ne[i])
        {
            if(dist[e[i]]>dist[v]+w[i])
            {
                dist[e[i]]=dist[v]+w[i];
                cnt[e[i]]+=1;
                if(cnt[e[i]]>=m+1) return true;//抽屉原理，多余m条边
                if(st[e[i]]==0)
                {
                    st[e[i]]=1;
                    q.push(e[i]);
                }
            }
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    memset(dist,0x3f,sizeof dist);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    if(spfa()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}