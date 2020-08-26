/*
 * @Description: 平衡二叉树判断
 * @Author: chunboo liu
 * @Date: 2020-08-17 16:24:28
 * @LastEditTime: 2020-08-19 09:06:11
 * @LastEditors: chunboo liu
 */
/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
Example 1:
Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

*/



#include<iostream>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
private:
    bool _isBalance=true;
public:

    int height(TreeNode* root)
        {
            if(!root || !_isBalance)
                return 0;
            int leftHeight=height(root->left);
            int rightHeight=height(root->right);
            bool isHighThanTwo=abs(leftHeight-rightHeight)>1;
            if(isHighThanTwo)
                _isBalance=false;
            return max(leftHeight,rightHeight)+1;
        }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        height(root);
        return _isBalance;
        // bool leftTreeBalance=isBalanced(root->left);
        // bool rightTreeBalance=isBalanced(root->right);
        // int maxDepthLeft=maximumDepthOfBinaryTree(root->left);
        // int maxDepthRight=maximumDepthOfBinaryTree(root->right);
        // return(leftTreeBalance&&rightTreeBalance&&abs(maxDepthLeft-maxDepthRight)<2);        
    }
};


int main()
{
    TreeNode root(1);
    
    TreeNode left1(2);
    TreeNode right1(2);
    
    TreeNode left2(3);
    TreeNode leftRight2(3);

    TreeNode left3(4);
    TreeNode leftRight3(4);

    root.left=&left1;
    root.right=& right1;

    // left1.left=&left2;
    // left1.right=&leftRight2;

    right1.left=&left3;
    right1.right=&leftRight3;
    // left3.left=&left2;

    Solution test;
    bool isBST=test.isBalanced(&root);
    cout<<"isBST: "<<(isBST?"True":"false")<<endl;

    return 0;
}