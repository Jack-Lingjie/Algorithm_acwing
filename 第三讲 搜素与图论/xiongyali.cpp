#include<iostream>
#include<cstring>
using namespace std;
const int N=510,M=100010;
int e[M],ne[M],h[N],idx=0;
int match[M];
bool st[M];
int n1,n2,m;
void add(int x,int y)
{
    e[idx]=y;
    ne[idx]=h[x];
    h[x]=idx++;
}
bool find(int x)
{
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            st[j]=true;
            if(match[j]==0||find(match[j]))
            {
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    memset(h,-1,sizeof h);
    cin>>n1>>n2>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    int res=0;
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++) st[j]=false;
        if(find(i))
        {
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}