#include<iostream>
using namespace std;
const int N=100010;
int stack[N],tt;
void init()
{
    tt=0;
}
void push(int x)
{
    stack[++tt]=x;
}
void pop()
{
    tt--;
}
bool empty()
{
    if(tt==0) return true;
    else return false;
}
int query()
{
    return stack[tt];
}
int main()
{
    int m;
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m;
    string op;
    int x;
    for(int i=0;i<m;i++)
    {
        cin>>op;
        if(op=="push")
        {
            cin>>x;
            push(x);
        }else if(op=="pop")
        {
            pop();
        }else if(op=="empty")
        {
            if(empty()) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else {
            cout<<query()<<endl;
        }
    }
    return 0;

}