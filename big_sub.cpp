#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int> &a,vector<int> &b){
    if(a.size()<b.size())
    {
        return false;
    }else if(a.size()==b.size())
    {
        int i=a.size()-1;
        while(i>=0&&a[i]==b[i]) i--;
        if(i==-1) return true;
        else return a[i]>=b[i];
    }else return true;
}
vector<int> sub(vector<int> a,vector<int> b)
{
    int i=0,t=0;
    vector<int> c;
    while(i<a.size())
    {
        t+=a[i];
        if(i<b.size()) t-=b[i];
        if(t<0) 
        {
            c.push_back((t+10)%10);
            t=(t+10)/10-1;
            // t/=10;
        }else{
            c.push_back(t);
            t/=10;
        }
        i++;
    }
    i=c.size()-1;
    while(c[i]==0&&i>=1)
    {
        c.pop_back();
        i--;
    }
    return c;
}
int main()
{
    string a,b;
    cin>>a>>b;
    vector<int> A;
    vector<int> B;
    for(int i=a.size()-1;i>=0;i--)
    {
        A.push_back(a[i]-'0');
    }
    for(int i=b.size()-1;i>=0;i--)
    {
        B.push_back(b[i]-'0');
    }
    vector<int> C;
    if(cmp(A,B))//A-B
    {
        C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--)
        {
            cout<<C[i];
        }
    }else{
        C=sub(B,A);
        cout<<"-";
        for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    }
    cout<<endl;
}