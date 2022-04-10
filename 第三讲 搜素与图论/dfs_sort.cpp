#include<iostream>
using namespace std;
const int N=10;
int path[N],visit[N];
void DFS(int now,int n)
{
    if(now==n)
    {
        for(int i=0;i<n;i++) cout<<path[i]<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        {
            visit[i]=1;
            path[now]=i+1;
            DFS(now+1,n);
            visit[i]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    DFS(0,n);
    return 0;
}
