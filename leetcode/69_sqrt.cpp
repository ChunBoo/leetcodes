/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-06-30 18:37:15
 * @LastEditTime: 2020-07-07 17:00:04
 * @LastEditors: chunbo liu
 */ 

#include<iostream>
using namespace std;

class solution
{
    public:
    int sqrt1(int x)
    {
        // double EPSINON = 0.001;
        long low = 0.0;
        long  high = x;
        long  mid = (low + high) / 2;
        if(x==0)
            return 0;
        if(x==1)
            return 1;
        while ((high - low) > 0){
            if (mid > x/mid){
                high = mid;
            }
            else{
                low = mid;
            }
            mid = (high + low) / 2;
        }
        return mid;
    }

    int sqrt2(int x)
    {
        if(x==0)
            return 0;
        int xi=1;
        int last=0;
        while((xi-last)>1)
        {
            last=xi;
            xi=(xi+x/xi)/2;
        }
        return xi;
    }
    int mySqrt(int x) {
        if(x<=1)
            return x;
        int low = 0.0;
        int high = x;
        while ((high - low) > 1){
            int  mid = (low + high) / 2;
            if (x/mid<mid)
            {
                high = mid;
            }
            else{
                low = mid;
            }
        }
        return low; 
    }
};

int main()
{
    int x=9;
    solution test;
    int ret=test.mySqrt(x);
    cout<<"result: "<<ret<<endl;
    return 0;
}