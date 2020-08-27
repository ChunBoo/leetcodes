/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-08-26 11:23:01
 * @LastEditTime: 2020-08-27 08:41:04
 * @LastEditors: chunbo liu
 */

/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction
(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.
Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    using cvecIterator=vector<int>::iterator;
    int maxProfit(vector<int>& prices) {
        cvecIterator begin=prices.begin();
        cvecIterator end=prices.end();
        int maxProfit=0,minValue=*begin;  
        if(end-begin==0)
            return 0;
  
        for(;begin!=end;begin++)
        {
            minValue=minValue>*begin?*begin:minValue;
            
            maxProfit=maxProfit<(*begin-minValue)?(*begin-minValue):maxProfit;
            // maxProfit=max(maxProfit,*begin-minValue);
        }       
        return maxProfit;
    }
};
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int min = INT_MAX;
        for (auto i : prices) {
            if (i < min) {
                min = i;
                continue;
            }
            if (i - min > max) {
                max = i - min;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> stockPrice{2,4,1};//{7,6,5,3,2,1};
    Solution test;
    int days=test.maxProfit(stockPrice);
    cout<<"Days: "<<days<<endl;

    return 0;
}