#include<iostream>
using namespace std;
void merge_sort(int q[],int left,int right)
{
    if(left>=right) return;
    // cout<<"right:"<<right<<"left: "<<left<<endl;
    int mid=(left+right)/2;
    merge_sort(q,left,mid);
    merge_sort(q,mid+1,right);
    int i=left,j=mid+1;
    int *temp=new int[right-left+1];
    int t=0;
    while(i<=mid&&j<=right)
    {
        if(q[i]<=q[j])
        {
            temp[t++]=q[i];
            i++;
        }else{
            temp[t++]=q[j];
            j++;
        }
    }
    while(i<=mid) temp[t++]=q[i++];
    while(j<=right) temp[t++]=q[j++];
    for(int i=left,j=0;i<=right;i++,j++)
    {
        q[i]=temp[j];
        // cout<<"i:"<<i<<" q[]  "<<q[i];
    }
    // cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}