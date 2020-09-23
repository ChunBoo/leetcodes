/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-22 08:28:22
 * @LastEditTime: 2020-09-23 09:09:39
 * @LastEditors: chunbo liu
 */

/*
Count the number of prime numbers less than a non-negative number, n.
Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> ret(n+1,true);
        int counter=0;
        int endVal=sqrt(n);
        for(int i=2;i<=endVal;i++)
        {
            if(ret[i])
            {
                for(int j=i*i;j<n;j+=i)
                    ret[j]=false;
            }
        }
        for(int k=2;k<n;k++)
        {
            if(ret[k])
                counter++;
        }
        return counter;
    }
};


int main()
{
    Solution test;
    int k=10;
    int result=test.countPrimes(k);
    cout<<"There are: "<<result<<" primes less than:"<<k<<endl;
    return 0;
}