#include<iostream>
using namespace std;
const int N=100010;
int queue[N],hh,tt;
void init()
{
    hh=tt=0;
}
void push(int x)
{
    queue[tt++]=x;
}
void pop()
{
    ++hh;
}
bool empty()
{
    if(hh==tt) return true;
    else return false;
}
int query()
{
    return queue[hh];
}
int main()
{
    init();
    int m;
    cin>>m;
    string op;
    int x;
    string s;
    
    for(int i=0;i<m;i++)
    {
        cin>>s;
        if(s=="push")
        {
            cin>>x;
            push(x);
        }else if(s=="empty")
        {
            if(empty()) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else if(s=="pop")
        {
            pop();
        }else {
            cout<<query()<<endl;
        }
    }
    return 0;
}