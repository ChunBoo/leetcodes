/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-09 10:12:10
 * @LastEditTime: 2020-09-10 19:39:38
 * @LastEditors: chunbo liu
 */
#include<iostream>
#include<string>

using namespace std;

class Solution 
{
    public:
        int titleToNumber(string s) 
        {
            int ret=0;
            if(s.empty())
                return 0;
            int size=s.size();
            for(int i=0;i<size;i++)
            {
                ret=ret*26+char(s[i]-'A'+1);
            }
            return ret;
        }
};

int main()
{
    int ret=0;
    Solution test;
    ret= test.titleToNumber("ZY");
    cout<<ret;
    return 0;

}