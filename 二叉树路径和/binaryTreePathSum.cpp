#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

const string s("1,2,4,2,3,");
vector<TreeNode*> vec;

void paraseStr(){
    //vector<TreeNode*> node_vec;
    if(s.empty())return;
    for(int i=0;i<s.size();++i){
        int value=0;
        while(s[i]!=','){
            if(s[i]=='#'){
                value=-1234;
            }
            else{
                value=value*10+s[i]-'0';
            }
            ++i;
        }
        if(value==-1234){
            vec.push_back(nullptr);
        }
        else{
            TreeNode *tmp=new TreeNode(value);
            vec.push_back(tmp);
        }
    }
}

TreeNode* createTree(){
    if(vec.empty())return nullptr;
    TreeNode *root=vec[0];
    queue<TreeNode*> node_queue;
    node_queue.push(root);
    int index=0;
    while(!node_queue.empty()){
        TreeNode *t=node_queue.front();
        if(index<vec.size()-2){
            t->left=vec[++index];
            t->right=vec[++index];
        }
        if(t->left!=nullptr){
            node_queue.push(t->left);
        }
        if(t->right!=nullptr){
            node_queue.push(t->right);
        }
        node_queue.pop();
    }
    return root;
}

class Solution{
    public:
        vector<vector<int>> binaryTreePathSum(TreeNode * root, int target){
            vector<vector<int> > res;
            if(root==nullptr)return res;
            vector<int> tmp;
            DFS(root,res,tmp,target);
            return res;
        }
        bool Isleaf(TreeNode *node){
            if(node->left==nullptr&&node->right==nullptr)return true;
            return false;
        }
        void DFS(TreeNode *root,vector<vector<int> > &ans,vector<int> &path,int key){
            if(root==nullptr)return;
            path.push_back(root->val);
            if(Isleaf(root)){
                if(key-root->val==0){
                    ans.push_back(path);
                    path.pop_back();
                    return;
                }
                else{
                    path.pop_back();
                    return;
                }
            }
            else{
                if(root->left){
                    DFS(root->left,ans,path,key-root->val);
                }
                if(root->right){
                    DFS(root->right,ans,path,key-root->val);
                }
            }
            path.pop_back();
            return;
        }
/*            if(root==nullptr)return;*/
            //if(key-root->val==0&&Isleaf(root)){   //终止条件
                //path.push_back(root->val);
                //ans.push_back(path);
                //return;
            //}
            //if(key-root->val!=0&&Isleaf(root)){
                //path.pop_back();
                //return;
            //}
            //if(root){
                //path.push_back(root->val);
            //}
            //if(root->left){       //如果路径和满足，则会无限循环
                ////if(key-root->val<0)return;
                ////if(key-root->val==0&&!Isleaf(root))return;
                ////path.push_back(root->val);
                //DFS(root->left,ans,path,key-root->val);
                ////path.pop_back();
            //}
            //if(root->right){
               //// if(key-root->val<0)return;
               //// if(key-root->val==0&&!Isleaf(root))return;
                ////path.push_back(root->val);
                //DFS(root->right,ans,path,key-root->val);
                ////path.pop_back();
            //}
            //path.pop_back();
            //return;
        //}
/*}*/};
//void preOrder(TreeNode *r){
    //if(r==nullptr){
        //return;
    //}
    //cout<<r->val<<",";
    //preOrder(r->left);
    //preOrder(r->right);
/*}*/
int main(){
    paraseStr();
    TreeNode *r=createTree();
    Solution c;
    vector<vector<int> > ans=c.binaryTreePathSum(r,5);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]<<",";
        }
        cout<<endl;

    }
    //preOrder(r);

    return 0;
}
