#include<iostream>
using namespace std;
const int N=100010,INF=1e9+10;
int f[N],arr[N],n;
int find(int x,int t)
{
    int mid,left=0,right=x;
    while(left<right)
    {
        mid=(left+right)/2;
        if(t>f[mid]) left=mid+1;
        else right=mid;
    }
    return left;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    f[0]=-INF;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int index=find(res,arr[i]);
        if(arr[i]>f[index])
        {
            f[index+1]=arr[i];
            res=max(res,index+1);
        }else{
            f[index]=arr[i];
        }
    }
    cout<<res<<endl;
    return 0;
}