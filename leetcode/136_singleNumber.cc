/*
 * @Description: given one vector,to find the only one number with others are twices
 * @Author: chunbo liu
 * @Date: 2020-09-01 09:18:11
 * @LastEditTime: 2020-09-01 09:21:19
 * @LastEditors: chunbo liu
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        int singleNumber(vector<int>& nums)
        {
            int ret=0;
            for(auto i: nums)
                ret^=i;
            return ret;
        }
};


int main()
{
    vector<int> num{1,9,1};
    Solution test;
    int result=test.singleNumber(num);
    cout<<"only one number is: "<<result<<endl;

    return 0;
}

