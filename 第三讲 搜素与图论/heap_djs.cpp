//850 采用堆优化djs算法
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=150010,INF=1e9+10;
int dist[N],h[N],e[N],ne[N],idx=0,weight[N],st[N];
int n,m;
typedef pair<int,int> PII;
void add(int x,int y,int z)
{
    e[idx]=y;
    weight[idx]=z;
    ne[idx]=h[x];
    h[x]=idx;
    idx++;
}
void djs()
{
    priority_queue<PII,vector<PII>,greater<PII>> q;
    dist[1]=0;
    q.push(make_pair(0,1));
    int counter=n;
    while(!q.empty())
    {
        PII top=q.top();
        q.pop();
        int t=top.second,d=top.first;
        // cout<<t<<" -<t "<<counter<<endl;
        if(st[t]==1) continue;//访问过
        st[t]=1;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            if(st[e[i]]==0&&weight[i]+d<dist[e[i]])
            {
                dist[e[i]]=weight[i]+d;
                q.push(make_pair(dist[e[i]],e[i]));
            }
            
        }
        // counter--;
        
    }
    // for(int i=1;i<=n;i++) cout<<dist[i]<<endl;
    if(dist[n]==INF) cout<<-1<<endl;
    else cout<<dist[n]<<endl;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) dist[i]=INF;
    for(int i=0;i<m;i++)
    {
        int  x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    djs();
    return 0;
}