#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int i=0,j=0;
    for(i=0,j=0;i<m;i++)
    {
        // cout<<"a:"<<a[i]<<"b:"<<b[j]<<endl;
        if(b[i]==a[j]) j++;
        if(j==n) 
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    // cout<<"j"<<j<<endl;
    if(j!=n ) cout<<"No"<<endl;
    return 0;
}