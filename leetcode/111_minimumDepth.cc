/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-08-21 11:28:55
 * @LastEditTime: 2020-08-21 13:51:16
 * @LastEditors: chunbo liu
 */

/*

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.
Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
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

  class Solution
  {
      public:
        int minimumDepth(TreeNode *root)
        {
            if(!root)
                return 0;
            else if(!root->left&&!root->right)
                return 1;
            else if(root->left&& !root->right)
                return minimumDepth(root->left)+1;
            else if(!root->left&&root->right)
                return minimumDepth(root->right)+1;
            int left_minimumDepth=minimumDepth(root->left);
            int right_minimumDepth=minimumDepth(root->right);
            return min(left_minimumDepth,right_minimumDepth)+1;
        }
  };


  int main()
  {
      TreeNode root(3);
      TreeNode left(9);
      TreeNode right(20);
      TreeNode rightleft(15);
      TreeNode rightRright(7);

      TreeNode newNode(111);

    //   root.left=&left;
      root.right=&right;

    //   left.left=&newNode;

      right.left=&rightleft;
      right.right=&rightRright;

      Solution test;

      int minimumDepthValue= test.minimumDepth(&root);

      cout<<minimumDepthValue<<endl;

      return 0;
  }