/*
 * @Description: 
 * @Author: chunboo liu
 * @Date: 2020-06-19 09:46:10
 * @LastEditTime: 2020-06-19 13:07:37
 * @LastEditors: chunboo liu
 */ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// (2->4->3) + (5->6->4)
// 342+465=807  7-->0-->8
#include<iostream>
#include<vector>
using namespace std;

struct  ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *retList;
        ListNode *header=new ListNode(0);
        retList=header;
        int carryFlag=0;
        while(l1&&l2)
        {
            int currentValue=l1->val+l2->val+carryFlag;
            if(currentValue>9)
            {
                currentValue-=10;
                carryFlag=1;
            }
            else
            {
                 carryFlag=0;
            }
            ListNode* currentNode=new ListNode(currentValue);
            header->next=currentNode;
            header=header->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l2)   //l1 is empty now
        {
            int currentValue=l2->val+carryFlag;
            carryFlag=currentValue>9?1:0;
            currentValue=(currentValue>9)?currentValue-10:currentValue;
            
            ListNode* newNode=new ListNode(currentValue);
            header->next=newNode;
            header=header->next;
            l2=l2->next;                      
        }
        while(l1)
        {
            int currentValue=l1->val+carryFlag;
            carryFlag=currentValue>=10?1:0;
            currentValue=(currentValue>=10)?currentValue-10:currentValue;
            
            ListNode* newNode=new ListNode(currentValue);
            header->next=newNode;
            header=header->next;
            l1=l1->next;  
        }
        if(carryFlag)
            {
                ListNode* lastNode= new ListNode(1);
                header->next=lastNode;
                
            }
        return retList->next;
    }
    ListNode* createList(vector<int> &ivec)
    {
        ListNode *retList;
        ListNode *header=new ListNode(0);
        retList=header;
        vector<int>::iterator it=ivec.begin();
        for(;it!=ivec.end();it++)
        {
            ListNode* newNode= new ListNode(*it);
            header->next=newNode;
            header=header->next;
        }
        return retList->next;
    }

    void displayList(ListNode *listPointer)
    {   
        ListNode* header=listPointer;
        while(header)
        {
            cout<<header->val<<" -->";
            header=header->next;
        }
    }
};

int main()
{
    vector<int> val1={1},val2={9,9};
    Solution test;
    ListNode* newList1=test.createList(val1);
    ListNode* newList2=test.createList(val2);
    // test.displayList(newList);
    ListNode* sumList=test.addTwoNumbers(newList1,newList2);
    test.displayList(sumList);
    return 0;
}