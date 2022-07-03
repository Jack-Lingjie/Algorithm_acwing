#include<iostream>
using namespace std;
const int N =1000010;
int arr[N],queue[N];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
   int hh=0,tt=-1;
   for(int i=0;i<n;i++)
   {
       if(tt>=hh&&queue[hh]<i-k+1) hh++;

       while(tt>=hh&&arr[queue[tt]]>arr[i]) tt--;
       queue[++tt]=i;

       if(i-k+1>=0)
       {
           cout<<arr[queue[hh]]<<" ";
       }
   }
   cout<<endl;
   hh=0;tt=-1;
   for(int i=0;i<n;i++)
   {
       if(tt>=hh&&queue[hh]<i-k+1) hh++;
       while(tt>=hh&&arr[queue[tt]]<arr[i]) tt--;
       queue[++tt]=i;

       if(i-k+1>=0)
       {
           cout<<arr[queue[hh]]<<" ";
       }
      
   }
    cout<<endl;
   return 0;
}