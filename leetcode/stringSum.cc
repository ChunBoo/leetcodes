/*
 * @Description: two integer strings added for sum
 * @Author: chunbo liu
 * @Date: 2020-08-21 14:01:17
 * @LastEditTime: 2020-08-21 16:51:30
 * @LastEditors: chunbo liu
 */

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

using stringIter=string::const_iterator;   //can not change the value which stringIter pointe to

void twoStringSum(const string& stra,const string& strb,string& ret)
{
    stringIter beginA=stra.begin();
    stringIter endA=stra.end();
    string temp;
    stringIter beginB=strb.begin();
    stringIter endB=strb.end();
    int sum=0;
    int carry=0;
    stringstream ss;
    while(endA!=beginA&&endB!=beginB)
    {
        int curA=*(--endA)-48;
        int curB=*(--endB)-48;
        cout<<curA<<' '<<curB<<endl;
        sum=curA+curB+carry;
        ss<<sum;
        ss>>temp;
         cout<<"temp= "<<temp<<endl;
        ret.append(temp);
        carry=(curA+curB+carry)>9?1:0;
    }
    
    while(endA!=beginA)
    {   
        int curA=*(--endA)-48;
        sum=curA+carry;
        ss<<sum;
        ss>>temp;
        ret.append(temp);
        carry=(curA+carry)>9?1:0;
        endA--;
    }

    while(endB!=beginB)
    {
        int curB=*(--endB)-48;
        sum=curB+carry;
        ss<<sum;
        ss>>temp;
       
        ret.append(temp);
        carry=(curB+carry)>9?1:0;
        endB--;
    }
    // cout<<ret;
}


int main()
{
    string stra("123");
    string strb("1");
    string result;
    twoStringSum(stra,strb,result);
    cout<<result<<endl;
    return 0;
}