/**
 * Definition for a binary tree node.*/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(!root)
            return root;
        invertTree(root->left);
        TreeNode* rightNode=root->right;
        root->right=root->left;
        root->left=rightNode;
        invertTree(root->left);
    }
    void preorderTree(TreeNode* root)
    {
        if(!root)
            return ;
        // vector<int> vecReturn;
        // vecReturn.push_back(root->val);
        cout<<root->val<<"-->";
        preorderTree(root->left);
        preorderTree(root->right);

    }
};

int main()
{
    TreeNode *root=new TreeNode(0);
    TreeNode *left1=new TreeNode(1);
    TreeNode *right1=new TreeNode(2);
    TreeNode *left2=new TreeNode(3);

    root->left=left1;
    root->right=right1;
    left1->left=left2;

    Solution test;
    test.preorderTree(root);
    cout<<"-----------"<<endl;
    test.invertTree(root);
    test.preorderTree(root);
    return 0;

}