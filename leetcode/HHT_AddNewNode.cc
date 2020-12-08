#include<iostream>
#include<vector>
struct ListNode
{
    int value{0};
    ListNode *next{nullptr};
};

void addNewNode(ListNode **pHead,int value)
{
    ListNode *pNew= new ListNode();
    pNew->next=nullptr;
    pNew->value=value;

    if(*pHead==nullptr)
        *pHead=pNew;
    //current List is not empty
    ListNode *pCurrent=*pHead;
    while(pCurrent->next)
        pCurrent=pCurrent->next;
    pCurrent->next=pNew;
}

void displayList(ListNode *pHead)
{
    if(!pHead)
        std::cout<<"ERROR:Empty List"<<std::endl;

    ListNode *pCurrent=pHead;
    while(pCurrent->next)
    {
        std::cout<<pCurrent->value<<"->";
        pCurrent=pCurrent->next;
    }
    std::cout<<pCurrent->value<<std::endl;
}

void printListReversedOrder(ListNode *pHead)
{
    if(pHead->next)
    {
        printListReversedOrder(pHead->next);
    }
    std::cout<<pHead->value<<"->";

}
 

int main()
{
    std::vector<int> ivec{1,2,3,4,5,6};
    ListNode *pHead=new ListNode();
    for(auto i:ivec)
    {
        addNewNode(&pHead,i);
    }
    std::cout<<"new List:"<<std::endl;
    displayList(pHead->next);
    std::cout<<"display reversed order"<<std::endl;
    printListReversedOrder(pHead->next);
    return 0;
}
