//867 分解质因数
#include<iostream>
using namespace std;
void divide(int n)
{
    int t=n;
    for(int i=2;i<=t/i;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                cnt++;
                n/=i;
            }
            cout<<i<<" "<<cnt<<endl;
        }
    }
    if(n>1) cout<<n<<" "<<1<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        divide(x);
        cout<<endl;
    }
}