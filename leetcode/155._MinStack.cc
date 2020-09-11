/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-09-03 13:56:28
 * @LastEditTime: 2020-09-05 14:13:34
 * @LastEditors: chunbo liu
 */
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
链接：https://leetcode-cn.com/problems/min-stack
*/


#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    int min;
    ListNode *next;
    ListNode(int x,int _min):val(x),min(_min){}
};



class MinStack {
    private:
        ListNode *head;
public:
    /** initialize your data structure here. */
    MinStack():head(nullptr) {
        head=new ListNode(0,INT16_MAX);
    }
    
    void push(int x) {
        if(!head)
        {
            head=new ListNode(x,x);
        }
        else
        {
            ListNode *currentNode =new ListNode(x,min(x,head->min));
            currentNode->next=head;
            head=currentNode;
        }
        
    }
    
    void pop() {
        head=head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main()
{
    MinStack *obj= new MinStack();
    obj->push(1);
    obj->pop();
    obj->push(3);
    obj->push(4);
    int param_3=obj->top();
    int param_4=obj->getMin();
    
    cout<<"param_3= "<<param_3<<endl;
    cout<<"parma_4= "<<param_4<<endl;

    return 0;
}