#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    const int N=3000010;
    vector<int> map_index(N);
    vector<int> prior(N);
    vector<pair<int,int>>  add;
    vector<pair<int,int>> query;
    map<int,int> index;
    for(int i=0;i<n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        index.insert({x,0});
    }
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        index.insert({l,0});
        index.insert({r,0});
    }
    //映射
    int i=0;
    for(map<int,int>::iterator it=index.begin();it!=index.end();it++)
    {
        it->second=i;
        i++;
    }
    
    //插入
    for(auto &item:add)
    {
        map_index[index[item.first]]+=item.second;
    }
    prior[1]=map_index[0];
    for(int i=1;i<index.size();i++)
    {
        prior[i+1]=prior[i]+map_index[i];
        // cout<<prior[i]<<endl;
    }
    for(auto &item : query)
    {
        cout<<prior[index[item.second]+1]-prior[index[item.first]]<<endl;
    }
    return 0;
}