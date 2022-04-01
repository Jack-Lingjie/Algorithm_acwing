#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;
void quicksort(int q[],int l,int r)//快速排序
{
    if(l>=r) return;
    int i=l,j=r,x=q[l];
    while(i<j)
    {
        while(q[i]<=x&&i<=r) i++;
        while(q[j]>=x&&j>=l) j--;
        if(j>i) swap(q[i],q[j]);
    }
    quicksort(q,l,j);
    quicksort(q,i,r);
}
const int N=100010;
int a[N];
int main()
{
    int n;
    cin>>n;
    // int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // sort(a,a+n);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}