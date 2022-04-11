#include<iostream>
using namespace std;
const int N=100010;
int stack[N];
int tt=-1;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(tt==-1)
        {
            cout<<"-1 ";
            stack[++tt]=x;//入栈
        }else{
            while(tt!=-1&&stack[tt]>=x) tt--;
            if(tt==-1) cout<<"-1 ";
            else cout<<stack[tt]<<" ";
            stack[++tt]=x;
            // {
            //     stack[tt--]
            // }
        }
    }
    return 0;
}