#include<iostream>
using namespace std;
long long reverse_pair(int *q,int left,int right)
{
    if(left>=right) return 0;
    int mid=(left+right)/2;
    int i=left,j=mid+1;
    long long lnum=reverse_pair(q,left,mid);
    long long rnum=reverse_pair(q,mid+1,right);
    long long sum=lnum+rnum;
    int *temp=new int[right-left+1];
    int t=0;
    // cout<<"sum:"<<sum<<"left"<<left<<"right"<<right<<endl;
    // for(int i=left;i<right-left+1;i++)
    // {
    //     cout<<q[i]<<" ";
    // }
    // cout<<endl;
    while(i<=mid&&j<=right)
    {
        if(q[i]>q[j])
        {
            // sum+=right-j+1;
            temp[t++]=q[j++];
        }else if(q[i]==q[j])
        {
            temp[t++]=q[i++];
            sum+=j-mid-1;
        }else 
        {
            sum+=j-mid-1;
            temp[t++]=q[i++];
        }
    }
    
    while(i<=mid)
    {
        sum+=right-mid;
        temp[t++]=q[i++];
    }
    while(j<=right) temp[t++]=q[j++];
    for(int i=left,j=0;i<=right;i++,j++)
    {
        q[i]=temp[j];
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long result=reverse_pair(a,0,n-1);
    cout<<result<<endl;
    return 0;
}