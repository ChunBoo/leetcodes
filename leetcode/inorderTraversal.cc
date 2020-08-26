/*
 * @Description: 中序遍历二叉树
 * @Author: chunboo liu
 * @Date: 2020-08-20 14:04:39
 * @LastEditTime: 2020-08-20 15:29:30
 * @LastEditors: chunboo liu
 */

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  
  TreeNode(int _val):val(_val),left(nullptr),right(nullptr){};  
};

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> ret;
    for(stack<TreeNode* > s;!s.empty()||root;)
    {
        if(root)
        {
            ret.push_back(root->val);
            s.push(root);
            root=root->left;
        }
        else
        {
            root=s.top();s.pop();
            root=root->right;
        }
    }
    return ret;
}


vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> ret;

    for(stack<TreeNode*> s;!s.empty()||root;)
    {
        if(root)
        {
            s.push(root);
            root=root->left;
        }
        else
        {
            root=s.top();s.pop();
            ret.push_back(root->val);
            root=root->right;
        }
    }
    return ret;
}

vector<int> postTraversal(TreeNode* root)
{
    vector<int> ret=preorderTraversal(root);
    reverse(ret.begin(),ret.end());
    return ret;  
}
int main()
{
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);

    TreeNode left2(4);
    TreeNode right2(5);
    
    TreeNode right22(6);
    root.left=&left;
    root.right=&right;

    left.left=&left2;
    left.right=&right2;
    right.right=&right22;
    // vector<int> ret=inorderTraversal(&root);
    // vector<int> ret=preorderTraversal(&root);
    vector<int> ret=postTraversal(&root);
    for(auto i:ret)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}