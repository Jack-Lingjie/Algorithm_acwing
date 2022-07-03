//899.最短编辑距离
//暴力解法即可
#include<iostream>
using namespace std;
const int N=1010;
int f[N][N];
string s[N];

int count(string &a,string &b)
{
        int n=a.length()-1,m=b.length()-1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
        {
            f[i][j]=min(f[i-1][j],f[i][j-1])+1;
            if(a[i]==b[j]) f[i][j]=min(f[i-1][j-1],f[i][j]);
            else f[i][j]=min(f[i-1][j-1]+1,f[i][j]);
        }
        return f[n][m];
}
int main()
{
    int n,m;
    string a,b;
    cin>>n>>m;
    //读入字符串
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        s[i]=" "+s[i];
    }
    //查询
    for(int i=0;i<N;i++) f[i][0]=i;
    for(int j=0;j<N;j++) f[0][j]=j;
    for(int i=0;i<m;i++)
    {
        string query;
        int bound;
        cin>>query>>bound;
        query=" "+query;
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(count(query,s[i])<=bound) res++;
        }
        cout<<res<<endl;
    }

    return 0;
}