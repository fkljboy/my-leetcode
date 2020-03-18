#
# @lc app=leetcode id=136 lang=python3
#
# [136] Single Number
#
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        n=len(nums)
        a=0
        for i in range(n):
            a=a^nums[i]
        return a
'''异或解法 类似c++解法


