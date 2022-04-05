#include<iostream>
#include<vector>
using namespace std;
vector<int> divide(vector<int> &A,int b,int &t)
{
    vector<int> C;
    for(int i=0;i<A.size();i++)
    {
        t+=A[i];
        // cout<<"t"<<t/b<<endl;
        C.push_back(t/b);
        t%=b;
        t*=10;
        
    }
    t/=10;
    return C;
}
int main()
{
    string a;
    int b;
    cin>>a;
    cin>>b;
    vector<int> A,C;
    int t=0;
    for(int i=0;i<a.size();i++)
    {
        A.push_back(a[i]-'0');
    }
    C=divide(A,b,t);
    // cout<<"c";
    // for(auto i:C) cout<<i<<" ";
    for(int i=0;i<C.size();i++)
    {
        if(C[i]!=0||i==C.size()-1)
        {
            for(int j=i;j<C.size();j++)
            cout<<C[j];
            break;
        }
    }
    cout<<endl<<t<<endl;;

    return 0;
}