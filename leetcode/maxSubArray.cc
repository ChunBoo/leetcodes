/*
 * @Description: 
 * @Author: chunboo liu
 * @Date: 2020-06-23 09:45:22
 * @LastEditTime: 2020-06-23 09:58:28
 * @LastEditors: chunboo liu
 */ 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class solution
{
    public:
        int maxSubArray(vector<int> &ivec)
        {
            // int result(0);
            int numsize(ivec.size());
            // vector<int>::iterator begin=ivec.begin();
            int dp(ivec[0]);
            int result=dp;
            for(auto i=1;i<numsize;i++)
            {
                dp=max(dp+ivec[i],ivec[i]);
                result=max(dp,result);
            }
            return result;
        }
};

int main()
{
    vector<int> inum={-2,1,-3,4,-1,2,1,-5,4};
    solution test;
    int ret=test.maxSubArray(inum);
    cout<<"value= "<<ret<<endl;
    return 0;

}