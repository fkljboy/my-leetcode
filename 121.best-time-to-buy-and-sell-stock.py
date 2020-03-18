#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if (len(prices)<=1):
            return 0
        min_p=prices[0]
        max_p=0
        for i in range(len(prices)):
            min_p= min(min_p,prices[i])
            max_p= max(max_p,prices[i]-min_p)
        return max_p

'''做法与c++做法类似
最大利润=max{前一天最大利润, 今天的价格 - 之前最低价格}