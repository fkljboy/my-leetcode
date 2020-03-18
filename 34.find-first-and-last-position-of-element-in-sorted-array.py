#
# @lc app=leetcode id=34 lang=python3
#
# [34] Find First and Last Position of Element in Sorted Array
#

# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res=[-1,-1]
        n=len(nums)
        for i in range(n):
            if nums[i]==target:
                res[0]=i
                break
        for j in range(n-1,-1,-1):
            if nums[j]==target:
                res[1]=j
                break
        return res

# @lc code=end

'''需要注意到Python的for循环的“顾头不顾尾”原则
