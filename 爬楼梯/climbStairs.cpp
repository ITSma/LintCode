#include "../MyOJHead.h"

class Solution{
    public:
        int climbStairs(int n){  //递归，斐波那契，会超时
            if(n==0)return 0;
            if(n==1)return 1;
            if(n==2)return 2;
            return climbStairs(n-1)+climbStairs(n-2);
        }
        int climbStairs(int n){  //迭代
            if(n==0)return 0;
            int sum1=0;
            int sum2=1;
            int sum=0;
            for(int i=1;i<=n;++i){
                sum=sum1+sum2;
                sum1=sum2;
                sum2=sum;
            }
            return sum;
        }
};
