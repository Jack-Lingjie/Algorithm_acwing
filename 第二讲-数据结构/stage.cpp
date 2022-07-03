#include<iostream>
#include<vector>
using namespace std;
int dp[100];
void climbStairs(int n) {
    // if (n <= 1) return n;
    /* 定义dp数组 */
    // vector<int> dp(n+1);
    /* 初始化dp数组 */
    dp[1] = 1;
    dp[2] = 2;
    /* 从前往后遍历 */
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
}
int main()
{
    int n=40;
    climbStairs(40);
    int ans=0;
    for(int i=1;i<=10;i++)
    {
        ans+=dp[i];
        // cout<<dp[i]<<" ";
    }
    cout<<ans;
}