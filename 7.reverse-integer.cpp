/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.21%)
 * Total Accepted:    634K
 * Total Submissions: 2.5M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

class Solution {
public:
    int reverse(int x) {
        string s =to_string(abs(x));                    
        char temp;
        int res;
        for(int i=0;i<s.size()/2;i++){
            temp=s[i];
            s[i]=s[s.size()-i-1];
            s[s.size()-i-1]=temp;
        }
        res=stoi(s);                            //向s中写入值
        if(res==INT_MAX)     //最大的溢出值
            return 0;
        if(x<0)
            res=-res;
        return res;
    }
};
/*stringstream ss;
        ss<<x;                                    //向流中传值
        string s=ss.str(); 
        stringstream既可以完成从string到int的转换 也可以完成从int到string的转换，以下是反向转换的代码示例：
        string result=”10000”;
        int n=0;
        stream<<result;
        stream>>n;
