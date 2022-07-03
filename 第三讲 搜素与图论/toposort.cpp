//848拓扑排序
//自环的点不能直接去掉
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=100010;
int h[N],e[N],ne[N],idx=0,d[N],path[N];//d是度
int n,m;
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
bool toposort()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0) 
        {
            q.push(i);
            // d[i]=-1;
        }
    }
    int t=0;
    while(!q.empty())
    {
        path[++t]=q.front();
        int now=path[t];
        q.pop();

        for(int i=h[now];i!=-1;i=ne[i])//遍历所有点
        {
            d[e[i]]--;
            if(d[e[i]]==0) q.push(e[i]);
        }
        
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]>0) return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==b) continue;//重边
        d[b]++;//入度+1
        add(a,b);
    }
    if(toposort())
    {
        for(int i=1;i<=n;i++) cout<<path[i]<<" ";
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}