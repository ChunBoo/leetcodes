/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-08-28 09:23:03
 * @LastEditTime: 2020-08-28 09:30:49
 * @LastEditors: chunbo liu
 */

#include<iostream>

struct  ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x){}
};

ListNode* Reverse(ListNode* header)
{
    if(!header||!header->next)
        return header;

    ListNode* current=header->next;
    ListNode* temp=nullptr;
    ListNode* previous=nullptr;

    while(current)
    {
        temp=current->next;
        current->next=previous;
        previous=current;
        current=temp;
    }

    header->next=previous;
    return header->next;
}

int main()
{

    ListNode* head=new ListNode(0);
    ListNode* first=new ListNode(1);
    ListNode* second=new ListNode(2);
    ListNode* third=new ListNode(3);
    head->next=first;
    first->next=second;
    second->next=third;
    ListNode* result=Reverse(head);
    while(result)
    {
        if(result->next)
            std::cout<<result->val<<"--->";
        else
            std::cout<<result->val;
        result=result->next;
    }

    return 0;
}
