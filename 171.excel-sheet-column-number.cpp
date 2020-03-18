/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
class Solution {
public:
    int titleToNumber(string s) {
        int a=s.size();
        int sum=0;
        double r=0,b=0;
        for (int i=0;i<a;i++){
            r=pow(26,a-i-1);
            b=((double)(s[i])-64)*r;
            sum+=b;
        }
        return sum;
    }
};
/*中规中矩的26进制转10进制 
