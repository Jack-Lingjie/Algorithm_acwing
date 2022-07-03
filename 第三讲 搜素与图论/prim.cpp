//prim算法最小生成树
#include<iostream>
#include<cstring>
using namespace std;
const int N=510,INF=0x3f3f3f3f;
int graph[N][N];
int dist[N],st[N];
int n,m;
int prim()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    // st[1]=1;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)//找到最小的点
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j]))

                t=j;
        }
        // cout<<"?"<<endl;
        //点到连通块的最小距离
        // cout<<"t:"<<dist[t]<<endl;
        if(dist[t]>=INF) return INF;
        res+=dist[t];
        // if(res>=INF) return INF;
        st[t]=1;
        for(int j=1;j<=n;j++)
        {
            
            if(!st[j]&&graph[t][j]<dist[j])
                dist[j]=graph[t][j];
        }
        
    }
    return res;
}
int main()
{
    cin>>n>>m;
    memset(graph,0x3f,sizeof graph);
    for(int i=1;i<=n;i++) graph[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        graph[x][y]=graph[y][x]=min(graph[x][y],z);
    }
    
    int res=prim();
    
    if(res==INF) cout<<"impossible"<<endl;
    else cout<<res<<endl;
    return 0;
}