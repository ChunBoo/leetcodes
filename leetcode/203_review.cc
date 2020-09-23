/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-22 08:57:04
 * @LastEditTime: 2020-09-22 19:32:26
 * @LastEditors: chunbo liu
 */


#include<iostream>
#include<vector>

using namespace std;

struct  ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next{nullptr}{}//next(nullptr){}
};


class solution
{
    public:
        ListNode* removeElements(ListNode* head,int val)
        {
            if(!head)
                return nullptr;
            ListNode *newHeader=new ListNode(-1);
            ListNode *pNode=newHeader;
            ListNode *delNode=newHeader;
            newHeader->next=head;
            while(pNode->next)
            {
                if(pNode->next->val==val)
                {
                    delNode= pNode->next;
                    pNode->next=pNode->next->next;
                    delete delNode;
                }
                else
                {
                    pNode=pNode->next;
                }            
            }
            return newHeader->next;
        }
};


ListNode* createLinkList(vector<int>& nums)
{
    if(nums.empty())
        return nullptr;
    ListNode* retHeader=new ListNode(-1);
    ListNode* curNode=retHeader;
    for(auto i:nums)
    {
        curNode->next=new ListNode(i);
        curNode=curNode->next;
    }
    return retHeader->next;
}

void displayLinkList(ListNode* header)
{
    if(!header)
        cout<<"Empty LinkList"<<endl;
    while(header)
    {
        if(header->next)
            cout<<header->val<<"->";
        else
        {
            cout<<header->val;
        }
        header=header->next;      
    }
    cout<<endl;
}


int main()
{
    vector<int> nums{1,2,3,4,5,2,8};
    ListNode *LL=createLinkList(nums);
    displayLinkList(LL);
    cout<<"-----------"<<endl;
    solution test;
    ListNode *newLL= test.removeElements(LL,2);
    displayLinkList(newLL);
    return 0;
}