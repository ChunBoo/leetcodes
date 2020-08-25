/*
 * @Description: 
 * @Author: chunbo liu
 * @Date: 2020-08-24 16:17:39
 * @LastEditTime: 2020-08-25 08:49:31
 * @LastEditors: chunbo liu
 */


/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that 
adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.
Example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool hasPathSumCore(TreeNode* root,int &sum_current,int sum,bool& flag)
    {
        if(flag)
            return true;
        if(!root)
            return false;

        if(root&&!root->left&&!root->right&&(sum_current+root->val)==sum)
            return true;

        sum_current+=root->val;
        bool left=hasPathSumCore(root->left,sum_current,sum,flag);
        if(!left)
            sum_current=sum_current-(root->left?root->left->val:0);
        bool right=hasPathSumCore(root->right,sum_current,sum,flag);
        if(!right)
            sum_current=sum_current-(root->right?root->right->val:0);

        flag=left||right;
        return flag;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        int sum_cur=0;
        bool flag=false;
        return hasPathSumCore(root,sum_cur,sum,flag);
    }
};

int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right= new TreeNode(3);
    TreeNode* left2=new TreeNode(4);
    TreeNode* right2=new TreeNode(5);

    root->left=left;
    root->right=right;
    
    left->left=left2;
    left->right=right2;

    Solution test;
    bool result= test.hasPathSum(root,4);

    cout<<"Result: "<<(result?"True":"False")<<endl;

    return 0;

}