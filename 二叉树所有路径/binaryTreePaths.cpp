#include "../MyOJHead.h"

class Solution{
public:
   vector<string> binaryTreePaths(TreeNode *root){
       vector<string> allPaths;
       string path;
       if(root==nullptr)return allPaths;
       DFS(root,allPaths,path);
       return allPaths;
    }
    void DFS(TreeNode *r,vector<string> &paths,string &onePath){
        if(r==nullptr)return;
        string str_of_val=to_string(r->val); //将节点转成string，考虑大数
        onePath.append(str_of_val);  //用append方法加入string，push_back方法只能加char
        if(r->left==nullptr&&r->right==nullptr){
            paths.push_back(onePath);  //符合要求，即到达根节点
            int cut_len=onePath.size()-str_of_val.size();  //计算将节点退出后的长度
            onePath=onePath.substr(0,cut_len);
            return;
        }
        onePath+="->";
        DFS(r->left,paths,onePath);
        DFS(r->right,paths,onePath);
        int pop_len=onePath.size()-str_of_val.size()-2;
        onePath=onePath.substr(0,pop_len);
        return;
    }
};

int main(){
    string node("1,2,3,#,5,");
    TreeNode *root=BinaryTree::createTree(node);

    Solution c;
    vector<string> res=c.binaryTreePaths(root);

    for(auto i:res){
        cout<<i<<endl;
    }

    return 0;
}
