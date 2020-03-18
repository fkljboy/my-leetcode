/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.81%)
 * Total Accepted:    366.6K
 * Total Submissions: 897.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=0;
        int len=digits.size();
        for(i=len-1;i>=0;i--)
        {
            if (digits[i]!=9)
            {
                digits[i]++;
                return digits;
            }
            else
                digits[i]=0;
            if (digits[0]==0)
                v.insert(v.begin(),1);
        }
        return digits;
    }
};
/* 解题思路： 遍历数组中的每一个元素 从最后一个开始 如果等于9则置零
并进入循环的下一个元素 再加一并判断 遍历到最后一个元素的时候 如果到
第一个元素的时候依然为零 则在最前面插入一个数字1 使用vector类的insert
函数
