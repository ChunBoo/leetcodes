/*
 * @Description: review of the 121
 * @Author: chunbo liu
 * @Date: 2020-08-27 09:08:31
 * @LastEditTime: 2020-08-27 09:16:01
 * @LastEditors: chunbo liu
 */

#include<iostream>
#include<vector>

using std::max;
using std::min;

class Solution
{
    public:
        int maxProfit(std::vector<int>& prices)
        {
            if(prices.empty())       
                return 0;

            int ret=0;
            int low=prices[0];
            for(auto price:prices)
            {
                low=min(low,price);
                ret=max(ret,price-low);
            }     
            return ret;
        }
};


int main()
{
    std::vector<int>  prices{2,4,8};
    Solution test;
    int result=test.maxProfit(prices);
    std::cout<<result<<std::endl;
    return 0;
}