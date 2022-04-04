#include<iostream>
using namespace std;
/*
递归版二分
*/
int binary_search_left(int *q,int left,int right,int x)
{
    
    if(left>=right)
    {
        if(q[left]==x) return left;
        else return -1;
    }
    int mid=(left+right)/2;
    // cout<<"mid"<<mid<<" "<<q[mid]<<endl;
    if(q[mid]<x) return binary_search_left(q,mid+1,right,x);
    else return binary_search_left(q,left,mid,x);
}
int binary_search_right(int *q,int left ,int right ,int x)
{
    if(left>=right) return left;
    int mid=(left+right+1)/2;
    if(q[mid]>x) return binary_search_right(q,left,mid-1,x);
    else return binary_search_right(q,mid,right,x);
}
int main()
{
    int n,q;
    cin>>n>>q;
    int *a=new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        int index;
        int left,right;
        if((index=binary_search_left(a,0,n-1,x))!=-1)
        {
            cout<<index<<" ";
            cout<<binary_search_right(a,0,n-1,x)<<endl;

        }else cout<<"-1 -1"<<endl;
        // cout<<"index:"<<index<<endl;
    }

    return 0;
}