#include<iostream>

#include<string>
#include<cmath>
using std::cout;

class Solution
{
    public:  
        int  lengthOfLengestSubString(std::string s)   //滑动窗口方式
        {
            size_t strSize=s.size();
            int start{0},end{0},length{0},result{0};
            while(end<strSize)
            {
                char tempChar=s[end];
                for(int index=start;index<end;index++)
                {
                    if(tempChar==s[index])
                    {
                        start=index+1;
                        length=end-start;
                        break;
                    }
                }
                end++;
                length++;
                result=std::max(result,length);
            }
            return result;
        }
};


int main()
{
    std::string s{"ababcdab"};
    Solution test;
    int longestLength=test.lengthOfLengestSubString(s);
    cout<<"longest length= "<<longestLength<<"\n";
    return 0;
}
