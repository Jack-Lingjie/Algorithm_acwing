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
    //公式：N=p_0^a_0*p_1^a_1*...*p_k^a_k;
    //sum=(p_0^0+p_0^1+...+p_0^a_0)(p_1^0+p_1^1+...+p_1^a_1)
    long long res=1;
    for(auto &prime:primes)
    {
        // res=(res*(prime.second+1))%mod;
        int p=prime.first;
        int num=prime.second;
        long long temp=1;
        for(int i=0;i<num;i++)
        {
            temp=(temp*p+1)%mod;
        }
        res=(res*temp)%mod;
    }
    cout<<res<<endl;
    return 0;
}