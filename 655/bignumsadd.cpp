class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        if(num1.empty()){
            return num2;
        }
        if(num2.empty()){
            return num1;
        }
        //int len=num1.size()>num2.size()?num1.size():num2.size();
        //if(num1.size()>num2.size()){
        //    return addStrings(num2,num1);
        //}
        int len1=num1.size()-1;
        int len2=num2.size()-1;
        int carry=0;
        int maxlen=len1>len2?len1:len2;
        char sum[maxlen+1];//注意这是maxlen+1
        int max=maxlen;    //后面maxlen要减减
        int s=0;
        while(len1>=0&&len2>=0){
            s=(num1[len1]-'0'+num2[len2]-'0')+carry;  //char转int  char-'0'
            carry=s/10;
            sum[maxlen]='0'+(s%10);
            len1--;
            len2--;
            maxlen--;
        }
        while(len1>=0){
            s=(num1[len1]-'0'+carry);
            carry=s/10;
            sum[maxlen]='0'+(s%10);
            len1--;
            maxlen--;
        }
        while(len2>=0){
            s=(num2[len2]-'0'+carry);
            carry=s/10;
            sum[maxlen]='0'+(s%10);
            len2--;
            maxlen--;
        }
        string res; //返回的是string
        for(int i=0;i<=max;++i){
               res+=sum[i];
        }
        if(carry){     //最后的进位
           //sum.insert(sum.begin(),'1');
           res="1"+res;
        }
        return res;
    }
};
