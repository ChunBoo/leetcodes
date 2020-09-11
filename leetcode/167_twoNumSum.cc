/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-07 14:10:36
 * @LastEditTime: 2020-09-08 08:48:21
 * @LastEditors: chunbo liu
 */
/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:
Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Constraints:
2 <= nums.length <= 3 * 104
-1000 <= nums[i] <= 1000
nums is sorted in increasing order.
-1000 <= target <= 1000
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum2(vector<int>& numbers, int target) 
    {
        int i=0,j=numbers.size()-1;
        while(i<j)
        {
            int tempSum=numbers[i]+numbers[j];
            if(tempSum==target)
                {return{i+1,j+1};}
            else if(tempSum<target)
                i++;
            else
            {
                j--;
            }
        }
         return {-1,-1};
    }

    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        map<int,int> ret;
        for(int i=0;i<numbers.size();i++)
        {
            auto found=ret.find(numbers[i]);
            if(found!=ret.end())
                return {found->second+1,i+1};
            ret.emplace(target-numbers[i],i);
        }
        return {-1,-1};
    }
};


int main()
{
    vector<int> nums={1,2,3,4,5,6,7};
    int target=10;
    Solution test;
    vector<int> result = test.twoSum2(nums,target);
    for(auto i:result)
        cout<<i<<" ";
    
    cout<<endl;
    return 0;
}