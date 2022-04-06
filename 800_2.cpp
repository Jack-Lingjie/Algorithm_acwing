#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];//读入a
    for(int i=0;i<m;i++) cin>>b[i];//读入b
    for(int i=0,j=m-1;i<n;i++)
    {
        while(j>=0&&a[i]+b[j]>x) j--;
        if(a[i]+b[j]==x) 
        {
            cout<<i<<" "<<j<<endl;
            break;
        }

    }
    return 0;
}