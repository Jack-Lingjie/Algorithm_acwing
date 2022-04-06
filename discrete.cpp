#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find(vector<int> &unique,int x)
{
    int left=0,right=unique.size()-1,mid=(left+right)/2;
    while(left<right)
    {
        mid=(left+right)/2;
        if(unique[mid]>=x) right=mid;
        else left=mid+1;
        // cout<<"left:"<<left<<endl;
    }
    return left;
}
const int N=300010;
int a[N],prior[N];
int main()
{

    // a[0];
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> add;
    vector<pair<int,int>> query;
    vector<int> index;
    for(int i=0;i<n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        index.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        index.push_back(l);
        index.push_back(r);
    }
    //唯一
    sort(index.begin(),index.end());
    index.erase(unique(index.begin(),index.end()),index.end());//唯一
    // cout<<"?"<<endl;
    for(auto item:add)//映射成数组
    {
        int x=find(index,item.first);
        a[x]+=item.second;
    }
    prior[0]=0;
    prior[1]=a[0];

    // cout<<endl;
    for(int i=1;i<index.size();i++)
    {
        prior[i+1]=a[i]+prior[i];
    }
    // for(int i=1;i<=index.size();i++)
    // {
    //     cout<<prior[i]<<" ";
    // }
    for(auto &item:query)
    {
        int l,r;
        l=find(index,item.first);
        r=find(index,item.second);
        // cout<<"l:"<<l<<" r:"<<r<<endl
        cout<<prior[r+1]-prior[l]<<endl;
    }
    // cout<<endl;
    return 0;
}