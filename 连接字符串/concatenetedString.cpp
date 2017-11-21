#include "../MyOJHead.h"

class Solution{
    public:
        string concatenetedString(string &s1,string &s2){
            if(s2.empty())return s1;
            string s;
            for(int i=0;i<s1.size();++i){
                if(s2.find(s1[i])==string::npos)  //s2中不存在该字符
                    s+=s1[i];
            }
            for(int i=0;i<s2.size();++i){
                if(s1.find(s2[i])==string::npos)
                    s+=s2[i];
            }
            return s;
        }
};

int main(int argc,char** argv){
    Solution c;
    string str1("aabcd");
    string str2("gafd");
    string ans=c.concatenetedString(str1,str2);

    cout<<ans<<endl;

    return 0;
}
