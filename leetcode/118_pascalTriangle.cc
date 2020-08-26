/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-08-25 10:38:19
 * @LastEditTime: 2020-08-25 13:15:08
 * @LastEditors: chunbo liu
 */

/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.
Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1],
 
]
*/

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows==0)
          return ret;

        for(int level=1;level<numRows+1;level++)
        {
          vector<int> currentLevel;
          if(level==1)
               currentLevel={1};
          else if (level==2)
               currentLevel={1,1};
          else
          {
               vector<int> lastVector{ret[level-2]};
               int previous=0;
               for(auto i:lastVector)
               {
                    currentLevel.push_back(i+previous);
                    previous=i;
               }
               currentLevel.push_back(1);
          }  
          ret.push_back(currentLevel);
        }
        return ret;
    }


        vector<vector<int>> generate2(int numRows) {
        vector<int> vec = {1};
        vector<vector<int>> res;
        while (numRows-- > 0)
        {
            res.push_back(vec);
            for (int i = vec.size() - 1; i >= 1; i--)
                vec[i] += (i - 1 >= 0 ? vec[i - 1] : 0);
            vec.push_back(1);
        }
        return res;
    }
};

int main()
{
     int rows=40;
     vector<vector<int>> pascalTriangle;

     Solution test;
     pascalTriangle=test.generate(rows);
     for(auto i:pascalTriangle)
     {
          cout<<"[ ";
          for(auto j:i)
               cout<<j<<",";
          cout<<" ]";
     }

     return 0;
}