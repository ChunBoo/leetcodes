/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-19 09:10:23
 * @LastEditTime: 2020-09-19 11:06:25
 * @LastEditors: chunbo liu
 */

/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/


#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:

    bool isHappy(int n)
    {
        int num=n;
        unordered_set<int> dict;
        while(dict.count(num)==0 && num!=1)
        {
            int next=0;
            dict.insert(num);
            while(num)
            {
                int modNumber=num%10;
                next+=modNumber*modNumber;
                num/=10;
            }
            num=next;
        }
        return num==1;
        
    }

    bool isHappy1(int n) 
    {
        bool ret=0;
        int cycleCounter=0;
        if(n==1)
            return true;
        while(ret!=1&&cycleCounter<100)
        {
            cycleCounter++;
            int temp=0;
            vector<int> elem;
            while(n)   
            {
                elem.push_back(n%10);
                n/=10;
            }
            for(auto i: elem )
            {
                temp+=i*i;
            }
            if(temp!=1)
            {
                ret==0; 
                n=temp;
            }
            else
            {
                ret=1;
                break;
            }  
        }
        return ret;
    }
};


int main()
{
    int n=2;
    Solution test;
    bool result=test.isHappy(n);
    cout<<n<<" is happynumber:"<<result<<endl;
    return 0;
}