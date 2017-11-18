/*class Solution{
    public:
        vector<vector<int> > levelOrder(TreeNode * root){
            vector<vector<int> > res;
            if(root==nullptr)return res;
            queue<TreeNode*> q1;
            queue<TreeNode*> q2;
            q1.push(root);
            vector<int> v1;
            vector<int> v2;     //需要两个队列来循环保存两层的节点
            while(!q1.empty()||!q2.empty()){
                while(!q1.empty()){
                    TreeNode *tmp=q1.front();
                        if(tmp->left)q2.push(tmp->left);
                        if(tmp->right)q2.push(tmp->right);
                        v1.push_back(tmp->val);
                        q1.pop();
                }
                if(!v1.empty())
                    res.push_back(v1);
                v1.clear();
                while(!q2.empty()){
                    TreeNode *tmp=q2.front();
                    if(tmp->left)q1.push(tmp->left);
                    if(tmp->right)q1.push(tmp->right);
                    v2.push_back(tmp->val);
                    q2.pop();
                }
                if(!v2.empty())
                    res.push_back(v2);
                v2.clear();
            }
            return res;
        }
};*/
class Solution{     //只需再加一个变量标记每层的最后一个节点即可
    public:
        vector<vector<int> > levelOrder(TreeNode * root){
            vector<vector<int> > res;
            if(root==nullptr)return res;
            queue<TreeNode*> q1;
           // queue<TreeNode*> q2;
            q1.push(root);
            TreeNode *flag=root;
            vector<int> v1;
           // vector<int> v2;
            while(!q1.empty()){
                TreeNode *tmp=q1.front();
                if(tmp->left)q1.push(tmp->left);
                if(tmp->right)q1.push(tmp->right);
                v1.push_back(tmp->val);
                if(tmp==flag){    //判断是否到了每层的最后一个节点
                    flag=q1.back();
                    res.push_back(v1);
                    v1.clear();
                }
                q1.pop();
            }
             return res;
        }
}
