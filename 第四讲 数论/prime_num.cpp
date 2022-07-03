#include<iostream>
#include<unordered_map>
using namespace std;
const int mod=1e9+7;
int main()
{
    int n;
    cin>>n;
    unordered_map<int,int> primes;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int t=a;
        for(int i=2;i<=t/i;i++)
        {
            if(a%i==0)
            {
                primes[i]+=1;
                while(a/=i,a%i==0)
                {
                    primes[i]+=1;
                }
            }
        }
        if(a>1) primes[a]+=1;
    }
    //求和
    //公式：N=p^a_0*p^a_1*...*p^a_k;
    //num=(a_0+1)*(a_1+1)*...*(a_k+1);
    long long res=1;
    for(auto &prime:primes)
    {
        res=(res*(prime.second+1))%mod;
    }
    cout<<res<<endl;
    return 0;
}