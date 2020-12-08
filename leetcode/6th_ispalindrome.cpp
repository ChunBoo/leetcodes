/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-06-29 18:21:56
 * @LastEditTime: 2020-06-29 18:29:26
 * @LastEditors: chunbo liu
 */ 

#include<iostream>
#include<limits>
using namespace std;

class solution
{
    public:
        bool isPalindrome(int x)
        {
            bool ret=false;
            if(x<0)
                return ret;
            long convertedValue=0;
            int tempValue=x;
            while(x)
            {
                convertedValue=convertedValue*10+x%10;
                x/=10;
            }
            return convertedValue==tempValue;
        }
};

int main()
{
    solution test;

    int data=121;
    bool result= test.isPalindrome(data);
    cout<<result<<endl;
    return 0;
    
}