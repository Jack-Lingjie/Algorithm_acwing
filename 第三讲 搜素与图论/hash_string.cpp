#include<iostream>
#include<string>
using namespace std;
const int N=100010,q=131;
unsigned long long h[N],p[N];
unsigned long long find(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    h[0]=0;
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*q+str[i-1];
        p[i]=p[i-1]*q;
    }

    for(int i=0;i<m;i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        if(find(x1,x2)==find(y1,y2))    cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}