#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int x;
    int number=1;
};
int find(int x,vector<Node> &p)
{
    if(x!=p[x].x) p[x].x=find(p[x].x,p);
    return p[x].x;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<Node> parent(n+1);
    for(int i=1;i<=n;i++)
    {
        parent[i].x=i;
        parent[i].number=1;
    }
    for(int i=0;i<m;i++)
    {
        string op;
        cin>>op;
        if(op=="C")
        {
            int a,b;
            cin>>a>>b;
            if(a==b) continue;
            if(find(a,parent)== find(b,parent)) continue;
            parent[find(b,parent)].number+=parent[find(a,parent)].number;
            parent[find(a,parent)].x=find(b,parent);

        }
        else if(op=="Q1")
        {
            int a,b;
            cin>>a>>b;
            if(find(a,parent)==find(b,parent)) cout<<"Yes"<<endl;//在同一个块
            else cout<<"No"<<endl;
        }else{
            int c;
            cin>>c;
            int p= find(c,parent);//找到父亲
            cout<<parent[p].number<<endl;
        }
    }
    return 0;
}

