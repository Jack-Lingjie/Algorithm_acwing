#include<iostream>
using namespace std;
const int N=100010;
int ne[N];
int main()
{
    int n,m;
    string s,p;
    cin>>m>>p>>n>>s;
    //求next数组
    ne[0]=-1;
    for(int i=1;i<m;i++)
    {
        int j=i-1;
        while(j!=-1&&p[i]!=p[ne[j]+1]) j=ne[j];
        if(j==-1) ne[i]=-1;
        else ne[i]=ne[j]+1;
    }
    for(int i=0,j=-1;i<n;i++)
    {
        while(j!=-1&&s[i]!=p[j+1]) j=ne[j];
        if(p[j+1]==s[i]) j++;
        if(j==m-1)
        {
            cout<<i-j<<" ";
            j=ne[j];
        }
        
    }
}