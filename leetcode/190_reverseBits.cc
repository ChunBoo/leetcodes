/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-15 19:12:00
 * @LastEditTime: 2020-09-15 19:47:43
 * @LastEditors: chunbo liu
 */

#include<iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        //进制的本质
        int i=32;
        while(i--)
        {
            cout<<"Before <<,ans="<<ans<<endl;
            ans<<=1;
            cout<<ans<<endl;
            ans+=n&1;
            n>>=1;
        }
        return ans;
    }


int main()
{
    uint32_t n=1;
    uint32_t ret=reverseBits(n);
    cout<<ret<<endl;
}