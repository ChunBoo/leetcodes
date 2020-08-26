/*
 * @Description: 快速排序算法
 * @Author: chunboo liu
 * @Date: 2020-08-03 17:10:58
 * @LastEditTime: 2020-08-03 17:26:53
 * @LastEditors: chunboo liu
 */

#include<iostream>
#include<vector>

using namespace std;

void quickSort(int left,int right,vector<int>& arr)
{
    if(left>=right)
        return;
    int i,j,base,tmp;
    i=left,j=right;
    base=arr[left];
    while(i<j)
    {
        while(arr[j]>=base&& i<j)
            j--;
        while(arr[i]<=base&& i<j)
            i++;
        if(i<j)
        {
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
    }
    arr[left]=arr[i];
    arr[i]=base;
    quickSort(left,i-1,arr);
    quickSort(i+1,right,arr);
}

int main()
{
    vector<int> ivec{6,4,2,1,5,9,3,7,8};
    quickSort(0,8,ivec);
    for(int i:ivec) cout<<i<<" "<<endl;
    return 0;
    
}