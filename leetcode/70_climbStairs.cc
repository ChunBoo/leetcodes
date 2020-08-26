/*
 * @Description: 动态规划算法的应用
 * @Author: chunboo liu
 * @Date: 2020-07-06 10:08:01
 * @LastEditTime: 2020-07-07 08:58:30
 * @LastEditors: chunboo liu
 */ 

#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int climbStairs(int n)
        {
            vector<int> dp(n+1,0);
            dp[1]=1;
            if(n>1)  dp[2]=2;
            for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
            return dp[n]; 
        }
};

int main()
{
    int n=4;
    Solution test;
    int ret=test.climbStairs(n);
    cout<<"ret= "<<ret<<endl;
    return 0;
}