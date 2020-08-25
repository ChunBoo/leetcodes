/*
 * @Description: 107 二叉树从底部到顶部的遍历，迭代算法
 * @Author: chunbo liu
 * @Date: 2020-07-30 15:36:06
 * @LastEditTime: 2020-08-14 09:19:53
 * @LastEditors: chunbo liu
 */ 

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Solution_copy {
public:


    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)return res;
        queue<TreeNode*> need;
       // queue<TreeNode*> need2;
        need.push(root);
        vector<int> temp;
        temp.push_back(root->val);
        res.push_back(temp);
       
            TreeNode* root1;
        while(need.empty()==false){

            int sizes=need.size();
            temp.clear();
            while(sizes-->0){
             root1=need.front();
            need.pop();

            if(root1->left!=NULL){need.push(root1->left);temp.push_back(root1->left->val);}
            if(root1->right!=NULL){need.push(root1->right);temp.push_back(root1->right->val);}
            }
            if(temp.size()!=0){
            //res.insert(res.begin(),temp);
            res.push_back(temp);}




class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> result;
      vector<int> levelNum;
      queue<TreeNode*> q;
      TreeNode *currentNode=root;
      q.push(currentNode);
      while(!q.empty())
      {
        int size=q.size();
        while(size-->0)
        {
          currentNode=q.front();
          q.pop();
          if(currentNode)
          {
            levelNum.push_back(currentNode->val);
            q.push(currentNode->left);
            q.push(currentNode->right);
          }
        }
        if(!levelNum.empty()) result.push_back(levelNum);
        levelNum.clear();
      }
      reverse(result.begin(),result.end());
      return result;
    }
};


int main()
{
  //create the binary tree now

  TreeNode root(1);
  TreeNode leftnode1(2);
  TreeNode rightnode1(3);
  TreeNode leftnode11(4);
  TreeNode rightnode12(5);
  TreeNode leftnode21(6);
  TreeNode rightnode22(7);

  root.left=&leftnode1;
  // root.right=&rightnode1;

  leftnode1.left=&leftnode11;
  leftnode1.right=&rightnode12;
  rightnode1.left=&leftnode21;
  // rightnode1.right=&rightnode22;

  Solution test;
  vector<vector<int>> ret=test.levelOrderBottom(&root);
  cout<<"result vector:"<<endl;
  for(auto i:ret)
    {
      cout<<"[";
      for(auto j:i)
        cout<<j<<" ";
      cout<<"]";
    }
  return 0;
}