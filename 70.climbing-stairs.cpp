/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (43.67%)
 * Total Accepted:    375.2K
 * Total Submissions: 857.5K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */
class Solution {
public:
    int climbStairs(int n) {
        vector<int> s;
	s.push_back(1);
	s.push_back(2);//先把头两个元素放进数组
	if (n == 1)
		return 1;
	if(n == 2)
		return 2;
	for (int i = 2; i < n; i++)
	{
		s.push_back(s[i - 1] + s[i - 2]); //用数组存储的方法去找F(n)
	}
	return s[n - 1];
    }
};
 /* 在总结了前几次的方案总次数以后，可以发现是一个斐波那契数列
 所以根据斐波拉契数列的通项公式f(n)=f(n-1)+f(n-2)通过对数列进行迭代就可以得到最终的解
