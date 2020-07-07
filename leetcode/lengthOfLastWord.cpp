#include<iostream>
#include<string>

using namespace std;

class Solution2 {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        int num=0;
        for(int i=len-1;i>=0;i--){
            if (s[i]!=' ')
                num++;
            else{
                if (num!=0)
                    return num;
            }
        }
        return num;
    }
};


class Solution{
public:
int lengthOfLastWord(string s){

    auto ssize = s.size();
    if(!ssize)
        return 0;
    int lastSpaceIdx=0,lastSecondSpace=0,count=0,lastCharIdx=0;
    // auto sbegin=s.begin();
    // auto send=s.end();
    decltype(s.size()) idx=0;
    for(;idx!=ssize;idx++)
    {

        if(isspace(s[idx]))
        {   
            lastSecondSpace=lastSpaceIdx;
            lastSpaceIdx = idx;
        }
        else
        {
            lastCharIdx = idx;
        }
        
    }
    for(;lastCharIdx>=0;lastCharIdx--)
    {
        if(!isspace(s[lastCharIdx]))
            count++;
        else
            break;        
    }
        return count;
    // if(lastSpaceIdx==ssize-1)
    //     lastSpaceIdx=lastSecondSpace;
    // if(lastSpaceIdx-lastCharIdx!=1)
    // for(;lastSpaceIdx!=ssize;lastSpaceIdx++)
    // {
    //     if(!isspace(s[lastSpaceIdx]))
    //         count++;
    // }

}
};

int main()
{
    Solution t;
    string s="  helloa ";//"b   a    ";
    int cnt=t.lengthOfLastWord(s);
    cout<<"cnt="<<cnt<<endl;
}

