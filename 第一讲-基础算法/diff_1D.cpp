#include<iostream>
#include<vector>
using namespace std;
void insert(vector<int> &arr,int i,int j,int x)//i 和 之间插入数j
{
    arr[i]+=x;
    arr[j+1]-=x;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        insert(arr1,i,i,x);
    }
    for(int i=0;i<m;i++)
    {
        int l,r,c;
        cin>>l>>r>>c;
        insert(arr1,l,r,c);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=arr1[i];
        cout<<sum<<" ";
    }
    cout<<endl;
}