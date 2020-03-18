#
# @lc app=leetcode id=122 lang=python3
#
# [122] Best Time to Buy and Sell Stock II
#
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        result = 0
        while i<len(prices)-1:        
            temp = prices[i+1]-prices[i] 
            if temp >0:
                result =result +temp
            i+=1            
        return result

'''与上一题不同的是 股票可以在当天当天卖出和买入，所以我们只需要统计所以的
上涨区间，并将所有的上涨区间累加即可，而下跌区间则不去考虑，下跌区间可以直接
跳过