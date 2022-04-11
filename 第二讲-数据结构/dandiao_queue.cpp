#include<iostream>
using namespace std;
const int N =1000010;
int arr[N],queue[N];
int main()
{
    int hh=0,tt=0;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        // if(hh!=tt) queue[tt++]=arr[i];//队列为空，进队
        // if(hh<i-k+1) hh++;//移动窗口
        // if(tt<hh) tt=hh;
        if(queue[hh]<i-k+1) hh++;
        while(hh!=tt&&arr[queue[tt-1]]>arr[i]) 
        {
            // cout<<tt<<endl;
            tt--;
        }
        queue[tt++]=i;
        // cout<<endl<<"hh"<<hh<<" " <<tt-1<<" "<<queue[tt-1]<<endl;
        if(i-k+1>=0) 
        {
            cout<<arr[queue[hh]]<<" ";
            // hh++;
        }
    }
    cout<<endl;

    //最大值
    hh=0;tt=0;
    for(int i=0;i<n;i++)
    {
        if(queue[hh]<i+1-k) hh++;
        while(hh!=tt&&arr[queue[tt-1]]<arr[i]) tt--;
        queue[tt++]=i;
        if(i-k+1>=0){
            cout<<arr[queue[hh]]<<" ";
        }
    }
    cout<<endl;
}