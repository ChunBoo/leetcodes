/*
 * @Description: 由有序数组生成二叉树
 * @Author: chunboo liu
 * @Date: 2020-08-17 15:55:23
 * @LastEditTime: 2020-08-20 13:29:05
 * @LastEditors: chunboo liu


Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/


#include<vector>
#include<iostream>
#include<stack>
using namespace std;
//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

vector<int> inorderTraversal(TreeNode *root) { 
    vector<int> ret;
    for (std::stack<TreeNode *> s; !s.empty() || root; )
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top(); s.pop();
            ret.push_back(root->val);
            root = root->right;
        }
    }
    return ret;
}

 
class Solution {
  public:

      using vecIter=vector<int>::iterator;
      
      TreeNode* sortedArrayToBST(vector<int>& nums) {
        vecIter begin= nums.begin();
        vecIter end=nums.end();  
        TreeNode* root=sortedArrayToBST(begin,end);
        return root;
      }

      TreeNode* sortedArrayToBST(vecIter begin,vecIter end)
      {
        if(end-begin==0)
            return nullptr;
        vecIter mid=begin+(end-begin)/2;
        TreeNode* leftNode=sortedArrayToBST(begin,mid);
        TreeNode* root=new TreeNode(*mid);
        root->left= leftNode;
        TreeNode* rightNode = sortedArrayToBST(next(mid),end);
        root->right=rightNode;
        return root;
      }
};

int main()
{
  vector<int> originVector{1,2,3,4,5,6,7,8};
  vector<int> ret;
  Solution test;
  TreeNode* root= test.sortedArrayToBST(originVector);
  
  ret=inorderTraversal(root);   //中序遍历

  for(auto i:ret)
    cout<<i<<' ';

  return 0;
}