#include <iostream>
#include<vector>
using namespace std;
int find(int x,vector<int> &p)
{
    if(x!=p[x]) p[x]=find(p[x],p);
    return p[x];
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++)
    {
        char op;
        int a,b;
        cin>>op>>a>>b;
        if(op=='M')//合并
        {
            parent[find(a,parent)]=find(b,parent);
        }
        else {//查询
            if(find(a,parent)==find(b,parent))//a,b属于同一个集合
            cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }

    }
    return 0;
}
