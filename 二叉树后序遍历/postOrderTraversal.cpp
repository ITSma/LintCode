#include "../MyOJHead.h"

class Solution{
public:
    vector<int> postorderTraversal(TreeNode *root){
        vector<int> res;
        if(root==nullptr)return res;
        postOrder(root,res);

        return res;
    }
    void postOrder(TreeNode *root,vector<int> &path){
        if(root==nullptr)return;
        postOrder(root->left,path);
        postOrder(root->right,path);
        path.push_back(root->val);
        return;
    }
};

int main(){
    string str("1,2,3,");
    TreeNode *root=BinaryTree::createTree(str);

    Solution c;
    vector<int> ans=c.postorderTraversal(root);

    for(auto i:ans){
        cout<<i<<",";
    }

    return 0;
}
