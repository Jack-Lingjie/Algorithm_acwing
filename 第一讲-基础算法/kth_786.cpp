#include<iostream>
#include<vector>
using namespace std;
int quick_sort(int *q,int left,int right,int k)
{
    if(left>=right) return q[left];
    int i=left-1,j=right+1,x=q[(left+right)/2];
    while(j>i)
    {
        while(q[++i]<x);
        while(q[--j]>x);
        if(j>i) swap(q[i],q[j]);
    }
    int nowth=j-left+1;
    if(nowth>=k) return quick_sort(q,left,j,k);
    else return quick_sort(q,j+1,right,k-nowth);
}
int main()
{
    int n,k;
    cin>>n>>k;
    int *a= new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int result=quick_sort(a,0,n-1,k);
    cout<<result<<endl;
    return 0;
}