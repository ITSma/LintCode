#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> treeNode;
        Traversal(root,treeNode);
        return treeNode;
    }
    void Traversal(TreeNode *root,vector<int> &res){
        if(root==nullptr)return;
        Traversal (root->left,res);
        res.push_back(root->val);
        Traversal (root->right,res);
    }
};
