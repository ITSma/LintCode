#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

const string str("1,2,3,#,5,6,#,");

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

//先序 反序列化
/*TreeNode* deserialize(const string s,int &index){*/
    //if(s[index]=='#'){
        //index+=2;
        //return nullptr;//空树
    //}
    //if(index>s.size()||s[index]==',')return nullptr;
    //int value=0;
    //while(s[index]!=','&&index<=s.size()){
        //value=value*10+s[index]-'0';
        //++index;
    //}
    //++index;
    //TreeNode *root=new TreeNode(value);
    //root->left=deserialize(s,index);
    //root->right=deserialize(s,index);

    //return root;
/*}*/
vector<TreeNode*> paraseString(const string s){
    vector<TreeNode*> vec_node;
    if(s.empty())return vec_node;
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
            vec_node.push_back(nullptr);
        }
        else{
            TreeNode *tmp=new TreeNode(value);
            vec_node.push_back(tmp);
        }
    }
    return vec_node;
}

TreeNode* levelDeserialize(vector<TreeNode*> vec){
    if(vec.empty())return nullptr;
    queue<TreeNode*> tree_queue;
    int i=0;
    TreeNode *root=vec[0];
    tree_queue.push(root);
    while(!tree_queue.empty()){
        TreeNode *node=tree_queue.front();
        if(i+2<vec.size()){
            TreeNode *l=vec[++i];
            TreeNode *r=vec[++i];
            node->left=l;
            node->right=r;
            if(l!=nullptr)
                tree_queue.push(l);
            if(r!=nullptr)
                tree_queue.push(r);
        }
       tree_queue.pop();
    }
    return root;
}
void preOder(TreeNode *r){//先序遍历
    if(r==nullptr){
        cout<<"#"<<",";//打印空节点
        return;//会把根节点的空节点也打印
    }
    cout<<r->val<<",";
    preOder(r->left);
    preOder(r->right);

    return;
}

int main()
{
    //TreeNode *root=new TreeNode(0);
    int n=0;
    vector<TreeNode*> v=paraseString(str);
    TreeNode *root=levelDeserialize(v);

    preOder(root);

    cout<<endl;
    return 0;
}
/*
void deserialize(TreeNode *&n,string s,int index){
    if(index==s.size())return;
    string tmp;
    while(s[index]!=','){
        tmp+=s[index];
        index++;
    }
    if(tmp!="#"){
        int value=stoi(tmp);
        n=new TreeNode(value);
        deserialize(n->left,s,index+1);
        deserialize(n->right,s,index+1);
    }
    else{
        n=nullptr;
        return;
    }
}
*/

