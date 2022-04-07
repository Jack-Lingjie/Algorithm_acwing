#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    unordered_map<int,int> a;
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        a[input]=i;
        // cout<<"i"<<i<<endl;
    }
    // cout<<endl<<a[2]<<endl;
    for(int i=0;i<m;i++)
    {
        int input;
        cin>>input;
        if(a.count(x-input)>0)
        {

            cout<<a[x-input]<<" "<<i<<endl;
            break;
        }
    }
    return 0;
}