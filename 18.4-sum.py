#
# @lc app=leetcode id=18 lang=python3
#
# [18] 4Sum
#

# @lc code=start
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res, k ,l= [], 0,0
        for k in range(len(nums) - 3):
            if k > 0 and nums[k] == nums[k - 1]: continue # 2. skip the same `nums[k]`.
            for l in range(k+1,len(nums)-2):
                if l > k+1 and nums[l] == nums[l - 1]: continue
                i, j = l + 1, len(nums) - 1
                while i < j : # 3. double pointer
                    s = nums[k] + nums[l]+nums[i] + nums[j]
                    if s < target:
                        i += 1
                    elif s > target:
                        j -= 1
                    else:
                        res.append([nums[k], nums[l],nums[i], nums[j]])
                        while i < j and nums[i] == nums[i + 1]: i += 1
                        while i < j and nums[j] == nums[j - 1]: j -= 1
                        i += 1
                        j -= 1               
        return res
'''双指针解法 和c++类似
# @lc code=end

