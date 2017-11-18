#ifndef MY_OJ_HEAD_H
#define MY_OJ_HEAD_H

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<math.h>
#include<priority_queue>
#include<algorithnm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class BinaryTree{
    public:
        static TreeNode* createTree(string str){
            vector<TreeNode*> node=splitSTR(str);
            if(node.empty())return nullptr;
            queue<TreeNode*> tmp;  //层次反序列化需要的队列
            TreeNode *root=node[0]; //树的根节点
            tmp.push(root);
            int node_nums=0;    //节点序号
            while(!tmp.empty()){
                TreeNode *r=tmp.front();
                if(node_nums<node.size()-1){
                    r->left=node[++node_nums];
                }
                if(node_nums<node.size()-1){
                    r->right=node[++node_nums];
                }
                if(r->left!=nullptr){   //非空节点入队，进行下一次的左右子树指定
                    tmp.push(r->left);
                }
                if(r->right!=nullptr){
                    tmp.push(r->right);
                }
                tmp.pop();
            }
            return root;
        }
    private:
        //空节点用'#'表示，字符串以','做分隔符。最后符号一定是','
        static vector<TreeNode*> splitSTR(string s){
            vector<TreeNode*> node_vec;
            if(s.empty())return node_vec;
            for(int i=0;i<s.size();++i){
                int value=0;
                while(s[i]!=','){ //以逗号,做分隔符取节点的值
                    if(s[i]=='#'){
                        value=-1234;
                    }
                    else{
                        value=value*10+s[i]-'0';
                    }
                    ++i;
                }
                if(value==-1234){   //按照value值解析，value=-1234，则是空节点，否则生成节点
                    node_vec.push_back(nullptr);
                }
                else{
                    TreeNode *tmp=new TreeNode(value);
                    node_vec.push_back(tmp);
                }
            }
            return node_vec;
        }
};

class List{

};

#endif
