#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> mul(vector<int> &A,int B)
{
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++)
    {
        // cout<<A[i]<<"  "<<B<<endl;
        t+=A[i]*B;
        C.push_back(t%10);
        t=t/10;
    }
    while(t>0)
    {
        C.push_back(t%10);
        t/=10;
    }
    while(C.back()==0&&C.size()>1)
    {
        C.pop_back();
    }
    return C;
}
int main()
{
    string a,b;
    cin>>a>>b;
    int B;
    vector<int> A,C;
    for(int i=a.size()-1;i>=0;i--)
    {
        A.push_back(a[i]-'0');
    }
    B=stoi(b);
    C=mul(A,B);
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    cout<<endl;
    return 0;
}