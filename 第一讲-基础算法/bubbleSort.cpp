//bubble sort 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cnt=0;//次数
    for(int i=0;i<n-1;i++)
    {
        bool change=false;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1]) 
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                change=true;
            }
            cnt++;
        }
        // if(!change) break;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}