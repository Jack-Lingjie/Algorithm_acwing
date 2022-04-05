#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> add(string a,string b)
{
    if(a.size()<b.size()) return add(b,a);
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
    int i=0,t=0;
    while(i<a.size())
    {
        t+=A[i];
        if(i<b.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
        i++;
    }
    return C;
}
int main()
{
    string a,b;
    cin>>a>>b;
    auto C=add(a,b);
    for(int i=C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }
    cout<<endl;
}