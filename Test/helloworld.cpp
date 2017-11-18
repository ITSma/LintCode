#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution{
public:
    void print(){
        cout<<"gdb-vim-test"<<endl;
    }
};

int main(){
    Solution c;
    c.print();
    cout<<"Hello World"<<endl;
    ListNode *head=new ListNode(100);
    cout<<head->val<<endl;
    return 0;
}
