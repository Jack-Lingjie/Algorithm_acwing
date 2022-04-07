#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    const int N=200010;
    int arr[N],prior[N];
    for(int i=1;i<=n;i++)
    {
        int t,c;
        cin>>t>>c;
        arr[max(0,t-k-c+1)]+=1;
        arr[max(0,t-k+1)]-=1;
        // cout<<"left:"<<max(0,t-k-c+1)<<" right:"<<max(0,t-k+1)<<endl;
        
    }
    // for(int i=0;i<30;i++) cout<<arr[i]<<" ";
    // cout<<endl;
    //前缀和
    prior[0]=arr[0];
    for(int i=1;i<N;i++)
    {
        prior[i]=prior[i-1]+arr[i];
    }
    // for(int i=0;i<100;i++) cout<< prior[i]<<" ";
    // cout<<endl;
    for(int i=0;i<m;i++)
    {
        int q;
        cin>>q;
        cout<<prior[q]<<endl;
    }
}