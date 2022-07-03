//846树的重心
#include<iostream>
#include<cstring>
using namespace std;
const int N=200010;//双向边，需要开两倍大小
int h[N],e[N],ne[N],idx=0,st[N];
int n;
int ans=N;
void add(int x,int y)//x->y
{
    e[idx]=y;
    ne[idx]=h[x];
    h[x]=idx;
    idx++;
}
int dfs(int x)
{
    int sum=0,res=0;
    // cout<<sum<<endl;
    for(int i=h[x];i!=-1;i=ne[i])//深度遍历每一个点
    {
        if(st[e[i]]==1) continue;
        st[e[i]]=1;
        int size;
        size=dfs(e[i]);
        res=max(res,size);//最大的
        sum+=size;
    }
    sum++;
    res=max(res,n-sum);
    ans=min(ans,res);
    
    return sum;

}
int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    
    dfs(1);
    // cout<<"ok"<<endl;
    cout<<ans<<endl;
    return 0;
}