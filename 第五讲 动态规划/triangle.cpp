//数字三角形
#include<iostream>
using namespace std;
const int N=510,INF=0x3f3f3f3f;
int arr[N][N];
int f[N][N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cin>>arr[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1) f[i][j]=f[i-1][j]+arr[i][j];
            else if(j==i) f[i][j]=f[i-1][j-1]+arr[i][j];
            else f[i][j]=max(f[i-1][j-1],f[i-1][j])+arr[i][j];
        }
    }   
    int res=-INF;
    for(int i=1;i<=n;i++) res=max(res,f[n][i]);
    cout<<res<<endl;
    return 0;
}