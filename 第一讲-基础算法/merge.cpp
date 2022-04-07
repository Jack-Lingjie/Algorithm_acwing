#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> merge(vector<pair<int,int>> &range)
{
    int start=-2e-9,end=-2e9;
    vector<pair<int,int>> res;
    for(auto &item:range)
    {
        if(item.first>end)//exist gap
        {
            if(end!=-2e9) res.push_back({start,end});
            start=item.first;
            end=item.second;
        }else{
            end=max(end,item.second);
        }
    }
    if(start!=-2e-9) res.push_back({start,end});
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> range;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        range.push_back({l,r});
    }
    sort(range.begin(),range.end());
    range=merge(range);
    cout<<range.size()<<endl;
    return 0;
}