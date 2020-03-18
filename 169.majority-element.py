#
# @lc app=leetcode id=169 lang=python3
#
# [169] Majority Element
#
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
         count=0
         flag=nums[0]
         for i in nums:
             if i==flag:
                 count=count+1
             else:
                 count=count-1
                 if count==0:
                     flag=i
                     count=1
         return flag
'''思路与c++的思路一致 
