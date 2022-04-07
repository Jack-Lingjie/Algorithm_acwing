#include<iostream>
#include<vector>
using namespace std;
void insert(vector<vector<int>> &arr,int x1,int y1,int x2,int y2,int c)
{
    arr[x1][y1]+=c;
    arr[x2+1][y1]-=c;
    arr[x1][y2+1]-=c;
    arr[x2+1][y2+1]+=c;
}
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> arr(n+2,vector<int>(m+2));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int c;
            cin>>c;
            insert(arr,i,j,i,j,c);
        }
    }
    for(int i=0;i<q;i++)
    {
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(arr,x1,y1,x2,y2,c);
    }
    for(int i=0;i<=n;i++) arr[i][0]=0;
    for(int i=0;i<=m;i++) arr[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}