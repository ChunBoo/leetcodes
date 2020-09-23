/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-21 16:05:49
 * @LastEditTime: 2020-09-21 18:35:33
 * @LastEditors: chunbo liu
 */

#include<iostream>
#include<vector>
using namespace std;


/*Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(vector<int>& nums)
{
    ListNode *header=new ListNode(-1);
    if(nums.empty())
        return nullptr;
    ListNode *curNode=header;
    for(auto i:nums)
    {
        curNode->next=new ListNode(i);
        curNode=curNode->next;
    }    
    return header->next;
}


void displayList(ListNode* header)
{
    if(!header)
        cout<<"Empty List"<<endl;
    ListNode* curNode=header;
    while(curNode)
    {
        if(curNode->next)
        {
            cout<<curNode->val<<"->";
        }
        else
        {
            cout<<curNode->val;    
        }
            curNode=curNode->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head)
            return head;

        ListNode* newHeader=new ListNode(-1);
        ListNode* deleteNode= nullptr;
        ListNode* preHeader=newHeader;
        newHeader->next=head;
        
        while(preHeader->next)
        {
            if(preHeader->next->val==val)
            {
                deleteNode=preHeader->next;
                preHeader->next=preHeader->next->next;
                delete deleteNode;
            }
            else
                preHeader=preHeader->next;
        }
        return newHeader->next;
    }
};

int main()
{
    vector<int> nums{1};
    ListNode *header=createList(nums);
    displayList(header);

    Solution test;
    ListNode* newHeader=test.removeElements(header,1);
    cout<<"------------"<<endl;
    displayList(newHeader);
    return 0;


}