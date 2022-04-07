#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int> &A,vector<int> &B)
{
    if(A.size()!=B.size()) return A.size()>=B.size();
    for(int i=A.size()-1;i>=0;i--)
    {
        if(A[i]!=B[i]) return A[i]>=B[i];
    }
    return true;
}
vector<int> sub(vector<int> &A,vector<int> &B)
{
    int i=0,t=0;
    vector<int> C;
    while(i<A.size())
    {
        t+=A[i];
        if(i<B.size()) t-=B[i];
        C.push_back((t+10)%10);
        
        if(t>=0) t=0;  //>=
        else t=-1;
        i++;
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
    vector<int> A,B,C;
    for(int i=a.size()-1;i>=0;i--)
    {
        A.push_back(a[i]-'0');
    }
    for(int i=b.size()-1;i>=0;i--)
    {
        B.push_back(b[i]-'0');
    }
    if(cmp(A,B))
    {
        C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--)
        {
            cout<<C[i];
        }
    }else{
        cout<<"-";
        C=sub(B,A);
        for(int i=C.size()-1;i>=0;i--)
        {
            cout<<C[i];
        }
    }
    cout<<endl;
    return 0;
}