//t842,排列数字，dfs
#include<iostream>
using namespace std;
const int N=10;
int st[N],row[N];
int n,length=0;
void dfs()
{
    if(length==n)//达到树底
    {
        for(int i=0;i<n;i++)
        {
            cout<<row[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])//未被访问过
        {
            st[i]=1;
            row[length]=i;
            length++;
            dfs();
            st[i]=0;
            length--;
        }
    }
}
int main()
{
    
    cin>>n;
    dfs();
    return 0;
}