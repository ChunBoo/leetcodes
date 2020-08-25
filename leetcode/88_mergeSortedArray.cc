/*
 * @Description: merge two sorted array
 * @Author: chunbo liu
 * @Date: 2020-07-13 14:49:58
 * @LastEditTime: 2020-07-14 13:50:33
 * @LastEditors: chunbo liu
 */ 

#include<iostream>
#include<vector>

using namespace std;
class Solution
{
    public:
        void mergeSortedArray(vector<int>& num1,int m,vector<int>& num2,int n)
        {
            ;
        }
        void mergeSortedArray2(int nums1[],int m,int nums2[],int n)
        {
            int lastPosition=m+n-1;
            int i=m-1,j=n-1;
            while(i>=0&&j>=0)
            {
                if(nums1[i]>=nums2[j])
                    nums1[lastPosition--]=nums1[i--];
                else
                    nums1[lastPosition--]=nums2[j--];
            }
            while(j>=0)
                nums1[lastPosition--]=nums2[j--];
            }
};

int main()
{
    // vector<int> num1={1,2,2,3,5};
    int a[6]={1,2,3,0,0,0};
    int b[]={2,5,6};
    // vector<int> num2={2,3,6,7};
    Solution t;
    // auto vSize=num1.size()+1;
    // num1[vSize]=99;
    t.mergeSortedArray2(a,3,b,3);
    for(int i=0;i<6;i++)
        cout<<a[i]<<endl;
    return 0;
}