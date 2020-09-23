/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-21 08:48:22
 * @LastEditTime: 2020-09-21 08:51:57
 * @LastEditors: chunbo liu
 */

#include<iostream>

using namespace std;

class solution
{
    public:
        int tailZeros(uint32_t n)
        {
            unsigned int i =32;
            unsigned int ret=0;
            while(i--)
            {
                ret+=n&1;
                n>>=1;
            }
            return ret;
        }
};


int main()
{
    unsigned int m=16;
    solution test;
    int result=test.tailZeros(m);
    cout<<result<<endl;
    return 0;
}