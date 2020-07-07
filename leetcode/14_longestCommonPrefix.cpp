/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-06-29 18:31:20
 * @LastEditTime: 2020-06-29 19:21:31
 * @LastEditors: chunbo liu
 */ 


#include<iostream>
#include<string>
#include<vector>
using namespace std;

class solution
{
    public:
        string longestCommonPrefix(vector<string> &strs)
        {
            if(strs.empty())            
                return "";
            else if(strs.size()==1)
                return strs[0];
            string tempString;
            bool isFound=true;
            for(auto i=0;i<strs[0].size();i++)
            {
                char currentChar=strs[0][i];
                for(auto subString:strs)
                {
                    if(i<subString.size()&& subString.at(i)!=currentChar)
                    {
                        isFound=false;
                        break;
                    }
                }
                if(isFound)
                    tempString+=currentChar;
                
            }
            return tempString;

        }
};

int main()
{
    solution test;
    vector<string> allStrings={"aa","a"};
    string result=test.longestCommonPrefix(allStrings);
    cout<<result<<endl;
    return 0;
}