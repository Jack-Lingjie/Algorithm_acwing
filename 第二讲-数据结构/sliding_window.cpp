#include<iostream>
using namespace std;
const int N=1000010;
const int INF=1e7;
int arr[N];
int minn[N];
int maxx[N];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n-k+1;i++)
    {
        minn[i]=INF;
        maxx[i]=-INF;

        for(int j=i;j<i+k;j++)
        {
            minn[i]=min(minn[i],arr[j]);
            maxx[i]=max(maxx[i],arr[j]);
        }
    }
    for(int i=0;i<n-k+1;i++) cout<<minn[i]<<" ";
    cout<<endl;
    for(int i=0;i<n-k+1;i++) cout<<maxx[i]<<" ";
    cout<<endl;
    return 0;
}