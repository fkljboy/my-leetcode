#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#
# https://leetcode.com/problems/two-sum/description/
#
# algorithms
# Easy (42.54%)
# Total Accepted:    1.6M
# Total Submissions: 3.7M
# Testcase Example:  '[2,7,11,15]\n9'
#
# Given an array of integers, return indices of the two numbers such that they
# add up to a specific target.
# 
# You may assume that each input would have exactly one solution, and you may
# not use the same element twice.
# 
# Example:
# 
# 
# Given nums = [2, 7, 11, 15], target = 9,
# 
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
# 
# 
# 
# 
#
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
         if not nums:
            return None
            
         d = {}
         for i, item in enumerate(nums):
             tmp  = target - item
            
             for key, value in d.items():
                 if value == tmp:
                     return [key, i]
            
             d[i] = item
            
         return None


 #简述以下这段算法的原理： 首先定义一个空的字典 将原数组num带入一个
 #索引序列 然后遍历这个序列的键值和内容，然后从第一个内容值开始依次遍历
 #所有的内容值，遍历的过程是逐渐扩充空字典的过程
