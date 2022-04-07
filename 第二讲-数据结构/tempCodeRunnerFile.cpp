#include<iostream>
using namespace std;
const int N=100010;
int son[N][26],cnt[N],id=0;
void insert(string s)
{
    int p=0;
    for(int i=0;i<s.size();i++)
    {
        int t=s[i]-'a';
        if(!son[p][t]) son[p][t]=++id;
        p=son[p][t];
    }
    cnt[p]++;
}
int query(string s)
{
    int p=0;
    for(int i=0;i<s.size();i++)
    {
        int t=s[i]-'a';
        if(!son[p][t]) return 0;
        p=son[p][t];
    }
    return cnt[p];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char oper;
        string s;
        cin>>oper>>s;
        if(oper=='I') insert(s);
        else {
            cout<<query(s);
        }
    }
    return 0;
}