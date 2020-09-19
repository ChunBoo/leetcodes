/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-16 09:28:51
 * @LastEditTime: 2020-09-16 09:32:23
 * @LastEditors: chunbo liu
 */

#include<iostream>

using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret=0;
        if(n==0)
            return ret;
        int i=32;
        while(i--)
        {
            ret+=(n&1)?1:0;
            n>>=1;
        }
        return ret;
    }
};