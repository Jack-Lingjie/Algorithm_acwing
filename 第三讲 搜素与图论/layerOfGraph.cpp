//图中点的层次
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100010;
int e[N],ne[N],idx=0,h[N],layer[N];
int n,m;
void add(int x,int y)
{
    e[idx]=y;
    ne[idx]=h[x];
    h[x]=idx;
    idx++;   
}
void bfs()
{
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int now=q.front();
        int son=h[now];
        q.pop();
        while(son!=-1)
        {
            if(layer[e[son]]==0)
           { 
                layer[e[son]]=layer[now]+1;
                q.push(e[son]);
           }
            son=ne[son];
        }
    }
    if(n==1) cout<<layer[n]<<endl;
    else  cout<<(layer[n]==0 ? -1 : layer[n]);
}
int main()
{
    
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==b) continue;
        add(a,b);
    }
    bfs();
    return 0;
}