#include "../MyOJHead.h"

/**************************
 * 给定一个二叉树，返回他的克隆品
**************************/

class Solution{
    public:
        TreeNode* cloneTree(TreeNode *root){
            if(root==nullptr)return nullptr;
            TreeNode *clone=new TreeNode(root->val);
            clone->left=cloneTree(root->left);
            clone->right=cloneTree(root->right);

            return clone;
        }
};

int main(){
    string str("1,2,3,4,5,");
    TreeNode *root=BinaryTree::createTree(str);

    Solution c;
    TreeNode *another=c.cloneTree(root);

    return 0;
}
