#include<iostream>
using namespace std;
long long reverse_pair(int *q,int left,int right)
{
    if(left>=right) return 0;
    int mid=(left+right)/2;
    int i=left,j=mid+1,t=0;
    int *temp=new int[right-left+1];
    long long sum=reverse_pair(q,left,mid)+reverse_pair(q,mid+1,right);

    while(i<=mid&&j<=right)
    {
        if(q[i]<=q[j]) temp[t++]=q[i++];
        else{
            sum+=mid-i+1;
            temp[t++]=q[j++];
        }
    }
    while(i<=mid) temp[t++]=q[i++];
    while(j<=right) temp[t++]=q[j++];
    for(int i=left,j=0;i<=right;i++,j++) q[i]=temp[j];
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<reverse_pair(a,0,n-1);
    return 0;
}