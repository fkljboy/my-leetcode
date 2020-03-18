#
# @lc app=leetcode id=189 lang=python3
#
# [189] Rotate Array
#
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        k=k%n
        nums[:]=nums[::-1]
        nums[:]=nums[k-1::-1]+nums[:k-1:-1]
#思路和c++的方法一类似

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        k=k%n
        for i in (range k):
            nums.insert(0,nums.pop())

#方法二 头插法  这个问题的核心还是要总结出 k=k%n的问题 方法有很多