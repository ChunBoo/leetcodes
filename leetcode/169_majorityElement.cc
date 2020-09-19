/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-10 10:38:28
 * @LastEditTime: 2020-09-14 10:24:12
 * @LastEditors: chunbo liu
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int ret=0,count=0;
        for(auto num:nums)
        {
            if(count==0)
            {
                ret=num;
                count=1;
            }
            else
            {
                if(ret!=num)
                {
                    count--;
                }
                else
                {
                    count++;
                }
                
            }
            
        }
    
        // for(auto i:nums)
        // {
        //     if(ret!=i)
        //     {
        //         count--;
        //         if(count<0)
        //         {
        //             ret=i;
        //             count=0;
        //         }
        //     }
        //     else
        //     {
        //         count++;
        //     }  
        // }
        // for(auto i:nums)
        // {
        //     if(i==ret)
        //         count++;
        //     else 
        //     {
        //         count--;
        //         if(count<0)
        //         {
        //             ret=i;
        //             count=0;
        //         }
        //     }
        // }
        count=0;
        for(auto i:nums)
        {
            if(i==ret)
                count++;
        }
        return {ret,count};
    }
};


int main()
{
    vector<int> nums{1,2,2,2,1,4,5,2,5,5};
    Solution test;
    vector<int> result= test.majorityElement(nums);
    vector<int>::iterator iter=result.begin();
    int majorElement=*iter;
    int count=*(++iter);
    cout<<"MajorElement= "<<majorElement <<" "<<"Counter= "<<count<<endl;
    return 0;
}