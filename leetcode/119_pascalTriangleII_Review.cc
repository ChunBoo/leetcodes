/*
 * @Description: using new method to generate the pascal triangle II
 * @Author: chunbo liu
 * @Date: 2020-08-27 08:59:53
 * @LastEditTime: 2020-08-27 09:07:12
 * @LastEditors: chunbo liu
 */

#include<iostream>
#include<vector>

using namespace std;


class Solution
{
    public:
        vector<int> getRow(int rowIndex)
        {
            rowIndex++;
            vector<int> res(rowIndex);
            res[0]=1;
            for(int i=0;i<rowIndex;i++)
            {
                res[i]=1;
                for(int j=i-1;j>0;j--)
                {
                    res[j]=res[j]+res[j-1];
                }
            }
            return res;
        }
};

int main()
{
    int rowcounter=5;
    Solution test;
    vector<int> result=test.getRow(rowcounter);
    cout<<"[";
    for(auto i=result.begin();i!=result.end();i++)
    {
        if(i!=result.end()-1)
            cout<<*i<<",";
        else
        {
            cout<<*i;
        }
    }
        cout<<"]"<<endl;
    return 0;
}