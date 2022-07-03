//筛质数
#include<iostream>
#include<queue>
using namespace std;
const int N=1e6+10;
bool st[N];
int main()
{
    int n;
    cin>>n;
    int res=0;
    queue<int> q;
    for(int i=2;i<=n;i++)
    {
        if(st[i]==false)
        {
            res++;//质数+1
            int t=i;
            while(t+=i,t<=n) st[t]=true;
        }
    }
    cout<<res<<endl;
    return 0;
}