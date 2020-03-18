#
# @lc app=leetcode id=309 lang=python3
#
# [309] Best Time to Buy and Sell Stock with Cooldown
#
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        if n==0:
            return 0
        dp_i_0,dp_i_1,dp_pre=0,-sys.maxsize,0
        for i in prices:
            temp=dp_i_0
            dp_i_0=max(dp_i_0,dp_i_1+i)
            dp_i_1=max(dp_i_1,dp_pre-i)
            dp_pre=temp
        return dp_i_0

"""python的解法和c++的解法类似 注意sys.maxsize 的取值

