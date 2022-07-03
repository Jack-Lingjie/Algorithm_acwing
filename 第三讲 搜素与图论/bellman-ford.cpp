//带负边的单源最短路径算法：bellman-ford算法
#include<iostream>
#include<cstring>
// #include
using namespace std;
const int N=510,M=10010;
int dist[N],backup[N],n,m,k;
struct Edge{
    int a,b,w;
}edges[M];
int bellman_ford()
{
    for(int i=0;i<k;i++)//k次循环
    {
        memcpy(backup,dist,sizeof dist);
        for(int i=0;i<m;i++)//对每一条边
        {
            if(dist[edges[i].b]>backup[edges[i].a]+edges[i].w)//松弛
            {
                dist[edges[i].b]=backup[edges[i].a]+edges[i].w;
            }
        }
    }
    return dist[n];
}
int main()
{
    cin>>n>>m>>k;
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<m;i++)
    {
        // int x,y,z;
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    }
    int res=bellman_ford();
    if(res>0x3f3f3f/2) cout<<"impossible"<<endl;
    else cout<<res;
    return 0;
}