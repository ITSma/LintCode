#include "../MyOJHead.h"

class Solution{
    public:
        bool checkSumOfSquareNumbers(int num){
            if(num<0)return false;
            if(num==0)return true;
            bool flag=false;
            int len=sqrt(num);
            for(int i=1;i<=len;++i){  //不等于len，1就错
                int left=num-i*i;
                if(sqrt(left)-(int)(sqrt(left))<0.000001)flag=true;
            }

            return flag;
        }
};

int main(){
    Solution c;
    if(c.checkSumOfSquareNumbers(400000006))
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
