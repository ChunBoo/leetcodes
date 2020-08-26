/*
 * @Description: 判断两个二叉树是否相同
 * @Author: chunboo liu
 * @Date: 2020-07-14 14:08:21
 * @LastEditTime: 2020-07-15 17:09:34
 * @LastEditors: chunboo liu
 */ 
#include<iostream>
using namespace std;
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
TreeNode* createTree(int nums[])
{
    
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p&&q) 
            return p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        else if(!p&&!q)
            return true;
        else
            return false;     
    }
};

int main()
{
    TreeNode *root1=new TreeNode(1);
    TreeNode *root2=new TreeNode(1);
    
    TreeNode *leftTree1= new TreeNode(2);
    TreeNode *rightTree1= new TreeNode(3);
    TreeNode *leftTree2= new TreeNode(2);
    TreeNode *rightTree2= new TreeNode(4);

    root1->left=leftTree1;
    root1->right=rightTree1;


    root2->left=leftTree2;
    root2->right=rightTree2;

    Solution test;
    bool ret=test.isSameTree(root1,root2);
    cout<<"is SameTree= "<<ret<<endl;
    


    
}