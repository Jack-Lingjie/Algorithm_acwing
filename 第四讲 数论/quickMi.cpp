#include<iostream>
using namespace std;
long long quickMi(long long a,long long b,long long k)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=(res*a)%k;
        // cout<<res<<endl;

        b=b>>1;
        a=(a*a)%k; 
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long a,b,p;
        cin>>a>>b>>p;
        cout<<quickMi(a,b,p)<<endl;
    }
    return 0;
}