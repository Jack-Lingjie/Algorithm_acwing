#include<iostream>
using namespace std;
const int N=100010;
int p[N],cnt[N];
int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        cnt[i]=1;
    }
    string s;
    int a,b;

    for(int i=0;i<m;i++)
    {
        cin>>s;
        if(s=="C")//插入
        {
            cin>>a>>b;
            if(find(a)==find(b)) continue;
            else{
                cnt[find(b)]+=cnt[find(a)];
                p[find(a)]=find(b);

            }
        }else if(s=="Q1")
        {
            cin>>a>>b;

            if(find(a)==find(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            cin>>a;
            cout<<cnt[find(a)]<<endl;
        }
    }
    return 0;
}
