#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> add(string a,string b)
{
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
    int i=0,j=0,t=0;
    vector<int> C;
    // cout<<i;
    while(i<A.size()&&j<B.size())
    {
        // cout<<i;
        C.push_back((A[i]+B[j]+t)%10);
        // cout<<(A[i]+B[j]+t)%10<<endl;
        t=(A[i]+B[j]+t)/10;
        i++;
        j++;
        
    }
    // for(auto &t:C) cout<<t;
    // cout<<endl;
    while(i<A.size())
    {
         C.push_back((A[i]+t)%10);
         t=(A[i]+t)/10;
         i++;
    }
    while(j<b.size()) 
    {
        C.push_back((B[j]+t)%10);
        t=(B[j]+t)/10;
        j++;
    }
    if(t>0) C.push_back(t);
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