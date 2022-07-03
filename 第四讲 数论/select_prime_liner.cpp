#include<iostream>
using namespace std;
const int N=1e6+10;
bool st[N];
int primes[N];
int main()
{
    int n;
    cin>>n;
    int res=0;
    for(int i=2;i<=n;i++)
    {
        if(!st[i]) primes[res++]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[i*primes[j]]=true;
            if(i%primes[j]==0) break;//最小质数,每个数都会被他的最小质数筛掉

        }
    }
    //每个合数都会被筛掉
    //证明
    //若X为合数，X/i<X,
    cout<<res<<endl;
    return 0;
}