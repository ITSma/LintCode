#include "../MyOJHead.h"
/*****************************
确定A中是否包含B中的所有字符；
不需要连续或有序；
字符都是大写；
*****************************/

class Solution{
    public:
        bool compareStrings(string &A,string &B){
            if(B.empty())return true;
            if(A.size()<B.size())return false;
            //int mapA[256]={0};
            int *mapA=new int[256]();
            int mapB[256]={0};
            for(int i=0;i<A.size();++i){
                mapA[A[i]]++;
            }
            for(int i=0;i<B.size();++i){
                mapB[B[i]]++;
            }
            for(int i=0;i<256;++i){
                if(mapB[i]!=0&&mapA[i]<mapB[i])
                        return false;
            }
            return true;
        }
};

int main(){
    string strA("ABC");
    string strB("A");
    Solution c;
    if(c.compareStrings(strA,strB)){
        cout<<"^_^"<<endl;
    }
    else
        cout<<"*-*"<<endl;

    return 0;
}
