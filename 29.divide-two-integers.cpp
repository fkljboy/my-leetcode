/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int res=0;
        if (dividend>0&&divisor>0){
            while(dividend>=0){
                dividend-=divisor;
                if (dividend>=0) res++;
            }
        }
         else if ((dividend>0&&divisor<0)||(dividend<0&&divisor>0)) {
             dividend=abs(dividend);
             divisor=abs(divisor);
             while(dividend>=0){
                dividend-=divisor;
                if (dividend>=0) res--;
         } 
         }
         else if (dividend<0&&divisor<0){
             while(dividend<=0){
                dividend-=divisor;
                if (dividend<=0) res++;
            }
         }
         else return 0;
         
         return res;
    }
};

// @lc code=end

if (dividend == 0) {
            return 0;
        }
        if (dividend == INT_MAX && divisor == -1) {
            return INT_MAX;
        }
        bool negative;
        if((dividend<0&&divisor<0)||(dividend>0&&divisor>0))   negative=false;
        int t = abs(dividend);
        int d= abs(divisor);
        int result = 0;
        for (int i=31; i>=0;i--) {
            if ((t>>i)>=d) {//找出足够大的数2^n*divisor
                result+=1<<i;//将结果加上2^n
                t-=d<<i;//将被除数减去2^n*divisor
            }
        }
        return negative ? -result : result;//符号相异取反

/*解题思路：这题是除法，所以先普及下除法术语
     * 商，公式是：(被除数-余数)÷除数=商，记作：被除数÷除数=商...余数，是一种数学术语。
     * 在一个除法算式里，被除数、余数、除数和商的关系为：(被除数-余数)÷除数=商，记作：被除数÷除数=商...余数，
     * 进而推导得出：商×除数+余数=被除数。
     *
     * 要求商，我们首先想到的是减法，能被减多少次，那么商就为多少，但是明显减法的效率太低
     *
     * 那么我们可以用位移法，因为计算机在做位移时效率特别高，向左移1相当于乘以2，向右位移1相当于除以2
     *
     * 我们可以把一个dividend（被除数）先除以2^n，n最初为31，不断减小n去试探,当某个n满足dividend/2^n>=divisor时，
     *
     * 表示我们找到了一个足够大的数，这个数*divisor是不大于dividend的，所以我们就可以减去2^n个divisor，以此类推
     *
     * 我们可以以100/3为例
     *
     * 2^n是1，2，4，8...2^31这种数，当n为31时，这个数特别大，100/2^n是一个很小的数，肯定是小于3的，所以循环下来，
     *
     * 当n=5时，100/32=3, 刚好是大于等于3的，这时我们将100-32*3=4，也就是减去了32个3，接下来我们再处理4，同样手法可以再减去一个3
     *
     * 所以一共是减去了33个3，所以商就是33