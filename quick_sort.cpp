#include<iostream>
using namespace std;
void quicksort(int q[],int left,int right)
{
    if(left>=right) return;
    int i=left-1,j=right+1,x=q[(left+right)/2];
    while(i<j)
    {
        while(q[++i]<x);
        while(q[--j]>x);
        if(j>i) swap(q[i],q[j]);
    }
    quicksort(q,left,j);
    quicksort(q,j+1,right);
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
    cout<<endl;
}