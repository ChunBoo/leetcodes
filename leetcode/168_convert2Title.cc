/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-08 14:18:49
 * @LastEditTime: 2020-09-09 09:58:24
 * @LastEditors: chunbo liu
 */


#include<string>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
    string convertToTitle(int n) {
        string title;
        if (n<0)
            return title;
        while(n)
        {
            n--;
            title.append(1,n%26+'A');
            n/=26;
        }
        reverse(title.begin(),title.end());
        return title;
    }


    string convertToTitle2(int n)
    {
        string title;
        if(n<0)
            return title;
        while(n)
        {
            n--;
            title=(char)(n%26+'A')+title;
            n/=26;
        }
        return title;
    }
};

int main()
{
    int i=52,j=701;
    Solution test;
    string ret1=test.convertToTitle2(i);
    string ret2=test.convertToTitle2(j);

    cout<<ret1<<"  "<<ret2;

    return 0;

}