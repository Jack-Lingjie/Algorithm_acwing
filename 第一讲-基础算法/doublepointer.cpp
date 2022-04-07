#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<int,int> visit;
    for(int i=0;i<n;i++) cin>>arr[i];
    int res=1;
    for(int i=0,j=0;i<n;i++)
    {
        visit[arr[i]]++;
        while(j<i&&visit[arr[i]]>1)
        {
            // if(visit[i]>1)
            // {
                visit[arr[j++]]--;
                // j++;
            // }
        }
        res=max(res,i-j+1);
    }
    cout<<res<<endl;
    return 0;
}