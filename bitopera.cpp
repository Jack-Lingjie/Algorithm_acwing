#include<iostream>
using namespace std;
int lowbit(int x)
{
    return x&(-x);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int sum=0;
        for(int i=x;i;i-=lowbit(i)) sum++;
        cout<<sum<<" ";
    }
    cout<<endl;
    return 0;
}