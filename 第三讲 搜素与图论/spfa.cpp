//spfa算法：带负边的单源最短路径，使用队列进行优化
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100010;
int e[N],ne[N],h[N],w[N],st[N],idx=0;
int dist[N];
int n,m;
void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
int spfa()
{
    queue<int> q;
    q.push(1);
    st[1]=1;
    dist[1]=0;

    for(int i=0;i<n;i++)
    {
        int count=q.size();
        while(count-->0)
        {
            int v=q.front();
            q.pop();
            for(int i=h[v];i!=-1;i=ne[i])
            {
                if(dist[e[i]]>dist[v]+w[i])//松弛
                {
                    dist[e[i]]=dist[v]+w[i];
                    if(st[e[i]]!=1)
                    {
                        q.push(e[i]);
                        st[e[i]]=1;
                    } 
                }
            }
            st[v]=0;    
        }
    }
    return dist[n];
}
int main()
{
    memset(h,-1,sizeof h);
    memset(dist,0x3f,sizeof dist);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    spfa();
    if(dist[n]>0x3f3f3f/2) cout<<"impossible"<<endl;
    else cout<<dist[n]<<endl;
    return 0;
}