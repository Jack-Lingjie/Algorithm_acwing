#include<iostream>
#include<vector>
using namespace std;
//前缀和
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=a[i-1]+x;
    }
    for(int i=0;i<m;i++)//查询
    {
        int x,y;
        cin>>x>>y;
        cout<<a[y]-a[x-1]<<endl;
    }
    return 0;
}