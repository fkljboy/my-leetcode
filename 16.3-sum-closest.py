#
# @lc app=leetcode id=16 lang=python3
#
# [16] 3Sum Closest
#

# @lc code=start
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n=len(nums)
        MIN=nums[0]+nums[1]+nums[2]
        for i in range(n-2):
            left=i+1
            right=n-1
            while( left<right):
                sum=nums[i]+nums[left]+nums[right]
                if (abs(sum-target)<abs(MIN-target)):
                    MIN=sum
                if sum<target:
                    left+=1
                elif sum>target:
                    right-=1
                else :
                    return MIN
        return MIN 
'''双指针法的python解决办法 还存在优化的空间 比如nums[i]和nums[i-1]相同时可以直接跳过
# @lc code=end

