//867 分解质因数
#include<iostream>
using namespace std;
void prime_divide(int n)
{
    int t=n;
    for(int i=2;i<=t/i;i++)
    {
        if(n%i==0)
        {
            int res=0;
            while(n%i==0)
            {
                res++;
                n/=i;
            }
            cout<<i<<" "<<res<<endl;
        }
        
    }
    if(n>1) cout<<n<<" 1"<<endl;
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        prime_divide(x);
    }
    return 0;
}