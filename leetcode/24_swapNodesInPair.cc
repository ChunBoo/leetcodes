/*
 @Description: 
 @Author: chunboo liu
 @Date: 2020-08-17 17:23:23
 * @LastEditTime: 2020-08-24 09:57:18
 * @LastEditors: chunboo liu
*/
/*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.
Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* createList(vector<int>& nums)
{
    vector<int>::iterator numsBegin=nums.begin();
    if(nums.empty())
        return nullptr;
    ListNode* header=new ListNode(*numsBegin++);
    for(ListNode* curNode=header;numsBegin!=nums.end();numsBegin++)
    {
        curNode->next=new ListNode(*numsBegin);
        curNode=curNode->next;
    }
    return header;
}

void displayList(ListNode* header)
{
    if(!header)
        cout<<"Empty List"<<endl;
    ListNode* currentNode=header;
    while(currentNode)
    {
        cout<<currentNode->val<<"->";
        currentNode=currentNode->next;
    }
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* next=head->next;
        head->next=swapPairs(next->next);
        next->next=head;
        return next;
    }
};


int main()
{

    vector<int> data{1,2,3,4,5};
    ListNode* header=createList(data);
        displayList(header);
    Solution test;
    ListNode* convertedListHeader= test.swapPairs(header);

    cout<<endl<<"--------------------"<<endl;
    displayList(convertedListHeader);

   return 0;
}
