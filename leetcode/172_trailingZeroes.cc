/*
 * @Description:   Given an integer n, return the number of trailing zeroes in n!.
 * @Author: chunbo liu
 * @Date: 2020-09-15 09:06:35
 * @LastEditTime: 2020-09-15 09:10:49
 * @LastEditors: chunbo liu
 */
#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ret=0;
        while(n/5>0)
        {
            ret+=n/5;
            n/=5;
        }
        return ret;
    }
};


int main()
{
    int n=25,m=30;
    Solution test;
    int retn=test.trailingZeroes(n);
    int retm=test.trailingZeroes(m);

    cout<<"n= "<<n<<",includes with: "<<retn<<" zeros"<<endl;
    cout<<"m= "<<m<<",includes with: "<<retm<<" zeros"<<endl;
    
    return 0;
    
}