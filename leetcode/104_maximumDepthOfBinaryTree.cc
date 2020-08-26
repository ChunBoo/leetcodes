/*
 * @Description: 二叉树最大深度
 * @Author: chunboo liu
 * @Date: 2020-07-21 17:23:06
 * @LastEditTime: 2020-07-22 10:20:24
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


class Solution
{
    public:
        int maximumDepthOfBinaryTree(TreeNode* root)
        {
            if(!root)
                return 0;
            return max(maximumDepthOfBinaryTree(root->left),maximumDepthOfBinaryTree(root->right))+1;
        }
};

int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* left1=new TreeNode(2);
    TreeNode* right1=new TreeNode(3);
    TreeNode* left2=new TreeNode(4);
    TreeNode* right2=new TreeNode(5);
    TreeNode* left3=new TreeNode(6);

    root->left=left1;
    root->right=right1;
    left1->left=left2;
    left1->right=right2;
    right1->left=left3;
    Solution test;
    int depth=test.maximumDepthOfBinaryTree(root);
    cout<<"Max depth= "<<depth<<endl;
    return 0;
}