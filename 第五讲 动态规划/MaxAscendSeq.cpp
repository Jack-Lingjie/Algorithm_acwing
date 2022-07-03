#include<iostream>
//最长上升子序列1
using namespace std;
const int N=1010,INF=0x3f3f3f3f;
int arr[N];
int f[N];//f[i]代表，以第i个数字结尾的最长上升子序列长度
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
        if(arr[i]>arr[j]) f[i]=max(f[i],f[j]+1);

    }
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,f[i]);
        
    cout<<res<<endl;
    return 0;
}