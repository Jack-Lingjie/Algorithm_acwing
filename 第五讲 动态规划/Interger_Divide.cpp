//900.整数划分
#include<iostream>
using namespace std;
const long long N=1010,MOD=1e9+7;
long long f[N];
int main()
{
    int n;
    cin>>n;
    f[0]=1;
    //滚动数组
    for(int i=1;i<=n;i++)
   {
         for(int j=i ;j <=n ; j++)  
        {
            f[j]=(f[j]+f[j-i])%MOD;

        }
}
    cout<<f[n]<<endl;
}

//二维方法
//900.整数划分
#include<iostream>
using namespace std;
const int N=1010,MOD=1e9+7;
int f[N][N];
int main()
{
    int n;
    cin>>n;
    f[0][0]=1;
    for(int  i=1;i<=n;i++) f[i][0]=1;
    for(int i=1;i<=n;i++)
   {
         for(int j=1 ;j <=n ; j++)
        {
            if(j>=i)
            f[i][j]=(f[i-1][j]+f[i][j-i])%MOD;
            else f[i][j]=f[i-1][j]%MOD;
        }
}
    cout<<f[n][n]<<endl;
}