#include<iostream>
using namespace std;
/*
非递归版，
分别使用二分查找找到左边界和有边界
*/
int main()
{
    int n,q;
    cin>>n>>q;
    int *a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    while(q-->0)
    {
        int x;
        cin>>x;
        int left=0,right=n-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(a[mid]>=x) right=mid;
            else left=mid+1;
        }
        if(a[left]!=x)
        {
            cout<<"-1 -1"<<endl;
        }else{
            cout<<left<<" ";
            int left=0,right=n-1;
            while(left<right)
            {
                int mid=(left+right+1)/2;
                if(a[mid]>x) right=mid-1;
                else left=mid;
            }
            cout<<left<<endl;
        }
    }
}