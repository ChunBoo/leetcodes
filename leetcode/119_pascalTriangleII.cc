/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-08-25 13:11:38
 * @LastEditTime: 2020-08-25 13:48:11
 * @LastEditors: chunbo liu
 */

/*
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
Notice that the row index starts from 0.
In Pascal's triangle, each number is the sum of the two numbers directly above it.
Follow up:
Could you optimize your algorithm to use only O(k) extra space?
Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]

Constraints:
0 <= rowIndex <= 40
*/

#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // vector<int> ret;
        vector<vector<int>> total_vector;
        if(rowIndex<0||rowIndex>40)
            return {};
        
        for(int currentLevel=1;currentLevel<=rowIndex+1;currentLevel++)
        {
            vector<int> currentVector;
            if(currentLevel==1)
                currentVector= {1};
            else if(currentLevel==2)
                currentVector={1,1};
            else
            {
                int previousValue=0;
                for(auto i: total_vector[currentLevel-2])
                {
                    currentVector.push_back(i+previousValue);
                    previousValue=i;
                }
                currentVector.push_back(1);
            }
            total_vector.push_back(currentVector);            
        }    
        return total_vector[rowIndex];
        // return ret;
    }
};

class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> res(rowIndex);
        res[0]=1;
        for(int i=0;i<rowIndex;i++){
            res[i]=1;
            for(int j=i-1;j>0;j--){
                res[j]=res[j]+res[j-1];
            }
        }
        return res;
    }
};

int main()
{
    int rowIndex=3;
    Solution test;
    vector<int> result=test.getRow(rowIndex);
    cout<<" [";
    for(auto i:result)
        cout<<i<<" ,";
    cout<<"]";
    return 0;
}