#include "../MyOJHead.h"

void preOder(TreeNode *root){
    if(root==nullptr)return;
    cout<<root->val<<",";
    preOder(root->left);
    preOder(root->right);
}

int main(){
    string ss("1,2,3,4,");
 //   BinaryTree bTree;

    TreeNode *root=BinaryTree::createTree(ss);
    preOder(root);

    cout<<endl;
    return 0;
}
