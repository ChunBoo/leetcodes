/*
 * @Description: 有序数组生成BST
 * @Author: chunbo liu
 * @Date: 2020-08-21 09:44:24
 * @LastEditTime: 2020-08-21 11:27:50
 * @LastEditors: chunbo liu
 */
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class Solution
{
    public:
        using vecTer=vector<int>::iterator;
        TreeNode* sortedArrayToBST(vector<int>& nums)
        {
            vecTer begin=nums.begin();
            vecTer end=nums.end();
            if(end-begin==0)
                return nullptr;
            return sortedArrayToBST(begin,end);   
        }

        TreeNode* sortedArrayToBST(vecTer begin,vecTer end)
        {
            if(end-begin==0)
                return nullptr;
            vecTer mid=begin+(end-begin)/2;
            TreeNode* left=sortedArrayToBST(begin,mid);
            TreeNode* root=new TreeNode(*mid);
            root->left=left;
            TreeNode* right =sortedArrayToBST(next(mid),end);
            root->right=right;
            return root;
        }
};

//using stack to save the treenodes
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
            root=s.top();
            s.pop();
            ret.push_back(root->val);
            root=root->right;
        }
    }
    return ret;
}

//preorder traversal
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> ret;
    for(stack<TreeNode*> s;!s.empty()||root;)
    {
        if(root)
        {
            s.push(root);
            ret.push_back(root->val);
            root=root->left;
        }
        else
        {
            root=s.top();
            s.pop();
            root=root->right;
        }
    }
    return ret;
}


int main()
{
    // TreeNode root('A');
    // TreeNode childB('B');
    // TreeNode childC('C');
    // TreeNode childD('D');
    // TreeNode childE('E');
    // TreeNode childF('F');
    // TreeNode childG('G');
    // root.left=&childB;
    // root.right=&childC;
    // childB.left=&childD;
    // childB.right=&childE;
    // childC.left=&childF;
    // childC.right=&childG;
    vector<int> nums={'A','B','C','D','E','F','G'};
    Solution test;
    TreeNode* newTree=test.sortedArrayToBST(nums);
    vector<int> ret=preorderTraversal(newTree);
    for(auto i:ret)
        cout<<char(i)<<' ';
    return 0;
    

}