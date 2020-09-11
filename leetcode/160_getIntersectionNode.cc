/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-05 14:28:46
 * @LastEditTime: 2020-09-07 11:01:26
 * @LastEditors: chunbo liu
 */

#include<iostream>
#include<vector>

using namespace std;


/**
 * Definition for singly-linked list.
 * */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode *createList(vector<int> &nums)
{
    ListNode *head=new ListNode(0);
    ListNode *ret=head;
    for(auto i:nums)
    {
        ListNode *currentNode=new ListNode(i);
        head->next=currentNode;
        head=head->next;
    }
    return ret->next;
}


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)
            return nullptr;
        
        ListNode * ha=headA,*hb=headB;
        while(ha!=hb)
        {
            ha=ha->next?ha->next:hb;
            hb=hb->next?hb->next:ha;
        }
        return ha;

    }
};

int main()
{
    vector<int> list1{4,1,8,4,5},list2{5,6,1,8,4,5};
       
}