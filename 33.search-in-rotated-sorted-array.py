#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
         left=0
         right=len(nums)-1
         while left<right :
             mid=(left+right)//2
             if nums[mid] < nums[right]:
                # 右半部分有序
                 if nums[mid + 1] <= target <= nums[right]:
                     left = mid + 1
                 else:
                     right = mid
             else:
                 if nums[left] <= target <= nums[mid]:
                     right = mid
                 else:
                     left = mid + 1
         if left==right and nums[left]==target:
             return left
         else :
             return -1
        # @lc code=end
'''1、中间元素和左边界比较，可以确定出一个区间有序，另一个区间无序；

2、中间元素和右边界比较，也可以确定出一个区间有序，另一个区间无序。