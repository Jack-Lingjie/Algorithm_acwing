//840模拟散列表
//拉链法
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
const int mod=100003;
int h[N],e[N],ne[N],idx=0;
void insert(int x)
{
    int t=(x%N+N)%mod;
    e[idx]=x;
    ne[idx]=h[t];
    h[t]=idx++;
}
bool find(int x)
{
    int t=(x%N+N)%mod;
    for(int i=h[t];i!=-1;i=ne[i])
    {
        if(e[i]==x) return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n;i++)
    {
        char op;
        int x;
        cin>>op;
        cin>>x;
        if(op=='I')
        {
            insert(x);
        }else{
            if(find(x)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}