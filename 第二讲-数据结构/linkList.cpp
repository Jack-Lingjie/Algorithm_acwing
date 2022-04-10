#include<iostream>
using namespace std;
const int N=100010;
int e[N],ne[N],head,idx;
void init()//初始化链表
{
    head=-1;
    idx=0;
}
void insert_head(int x)//头插
{
    e[idx]=x;
    ne[idx]=head;
    head=idx++;
}
void insert_k(int k,int x)
{
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
void remove(int k)
{
    ne[k]=ne[ne[k]];
}
int main()
{
    int  m;
    cin>>m;
    init();
    for(int i=0;i<m;i++)
    {
        char op;
        int k,x;
        cin>>op;
        if(op=='H')//插入
        {
            cin>>x;
            insert_head(x);
        }else if(op=='D')
        {
            cin>>k;
            if(k==0)
            {
                head=ne[head];
            }
            remove(k-1);
        }else{
            cin>>k>>x;
            insert_k(k-1,x);
        }
    }
    for(int i=head;i!=-1;i=ne[i])
    {
        cout<<e[i]<<" ";
    }
}