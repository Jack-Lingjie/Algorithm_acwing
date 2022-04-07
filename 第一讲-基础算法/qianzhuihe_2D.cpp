#include<iostream>
#include<vector>
using namespace std;
//二维前缀和
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> arr(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++) arr[i][0]=0;
    for(int j=0;j<=m;j++) arr[0][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+x;
        }

    for(int i=0;i<q;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1]<<endl;
    }
    return 0;
}