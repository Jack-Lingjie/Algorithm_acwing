#include<iostream>
using namespace std;
const int N=100010;
int head,tail,left[N],right[N],e[N],idx;
void init()
{
    right[0]=1;
    left[0]=-1;
    left[1]=0;
    right[1]=-1;
    idx=2;
}
void insert(int k,int x)
{
    e[idx]=x;
    right[idx]=right[k];//新结点指向前后结点
    left[idx]=left[right[k]];

    left[right[idx]]=idx;
    left[k]=idx;
    idx++;
}
void remove(int k)
{
    right[left[k]]=right[k];
    left[right[k]]=left[k];
}
int main()
{
    int m;
    cin>>m;
    string op;
    int k,x;
    for(int i=0;i<m;i++)
    {
        cin>>op;
        if(op=="L")//最左端插入数据
        {
            cin>>x;
            insert(0,x);
        }else if(op=="R")//最右端插入
        {
            cin>>x;
            insert(left[1],x);
        }else if(op=="D")//删除
        {
            cin>>k;
            remove(k+1);
        }else if(op=="IL")//左插
        {
            cin>>k>>x;
            insert(left[k],x);
        }else {
            cin>>k>>x;
            insert(k,x);
        }
    }
    //输出
    for(int i=0;i!=-;i=right[i])
    {
        cout<<e[i]<<" ";
    }
    cout<<endl;
    return 0;
}