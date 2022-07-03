//kruskal算法
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200010;
int p[N],n,m;
struct Edge{
    int a,b,w;
    bool operator<(Edge &e) const{
        return this->w<e.w;
    }
}edges[N];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    }
    sort(edges,edges+m);
    int res=0,cnt=1;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=0;i<m;i++)
    {
        if(find(edges[i].a)!=find(edges[i].b))//不在同一个图中
        {
            p[find(edges[i].a)]=find(edges[i].b);
            res+=edges[i].w;
            cnt++;
        }
        if(cnt==n) break;
    }
    if(cnt==n) cout<<res<<endl;
    else cout<<"impossible"<<endl;
    return 0;
}