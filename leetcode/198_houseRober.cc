/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-16 14:50:01
 * @LastEditTime: 2020-09-18 09:21:32
 * @LastEditors: chunbo liu
 */

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine 
the maximum amount of money you can rob tonight without alerting the police.
Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

*/

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    
    int rob(vector<int>& nums) 
    {
        int ret=0;
        auto vectorSize=nums.size();
        if(vectorSize==0)
            return ret;
        vector<int> dp(vectorSize,0);
        int a=0,b=0;
        for(int i=0;i<vectorSize;i++)
        {
            dp[i]=max(a+nums[i],b);
            a=b;
            b=dp[i];
        }
        return dp[vectorSize-1];
    }

    
    int rob2(vector<int>& nums) {
        int ret=0;
        int numCount=nums.size();
        if(numCount==0)
            return ret;
        if(numCount==1)
            return nums[0];
        // int vectorSize=nums.size();
        int dp[numCount];

        int a=nums[0],b=max(nums[0],nums[1]);
        dp[0]=nums[0],dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<numCount;i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        
        return dp[numCount-1];
    }
};

int main()
{
    vector<int> nums{2,1,1,2};
    Solution test;
    int result=test.rob(nums);
    cout<<result<<endl;
    return 0;
}