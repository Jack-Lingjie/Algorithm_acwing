#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;
void quicksort(int q[],int l,int r)//快速排序
{
    if(l>=r) return;
    int i=l-1,j=r+1,x=q[(l+r)/2];
    while(i<j)
    {
        while(q[++i]<x);
        while(q[--j]>x) ;
        if(j>i) swap(q[i],q[j]);
    }
    quicksort(q,l,j);
    quicksort(q,j+1,r);
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
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}