//负环
//bellman-ford算法判断，若第n+1次遍历边时能够松弛距离，则存在负环，否则，不存在负环
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
int dist[N],backup[N];//需要备份，防止串行
struct Edge{
    int a,b,w;
}edges[N];
int n,m;
bool bellman_ford()
{
    dist[1]=0;
    for(int i=0;i<n;i++)
    {
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++)//松弛
        {
            if(dist[edges[j].b]>backup[edges[j].a]+edges[j].w)
            {
                dist[edges[j].b]=backup[edges[j].a]+edges[j].w;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(dist[edges[i].b]>dist[edges[i].a]+edges[i].w)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin>>n>>m;
    memset(dist,0x3f,sizeof dist);
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    } 
    if(!bellman_ford())
    {
        cout<<"Yes"<<endl;

    }  else{
        cout<<"No"<<endl;
    }
    return 0;
}