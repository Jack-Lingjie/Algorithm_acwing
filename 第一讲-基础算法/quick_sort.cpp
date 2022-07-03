#include<iostream>
using namespace std;
const int N=100010;
int arr[N];
int n;
void quick_sort(int l,int r)
{
    if(l>=r) return ;
    int i=l-1,j=r+1;
    int mid=arr[(l+r)/2];
    while(j>i)
    {
        while(arr[++i]<mid);
        while(arr[--j]>mid);
        if(j>i) swap(arr[i],arr[j]);
    }
    quick_sort(l,j);
    quick_sort(j+1,r);
}
int main()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quick_sort(0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}