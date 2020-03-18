#
# @lc app=leetcode id=39 lang=python3
#
# [39] Combination Sum
#
# https://leetcode.com/problems/combination-sum/description/
#
# algorithms
# Medium (47.18%)
# Total Accepted:    318.8K
# Total Submissions: 673.3K
# Testcase Example:  '[2,3,6,7]\n7'
#
# Given a set of candidate numbers (candidates) (without duplicates) and a
# target number (target), find all unique combinations in candidates where the
# candidate numbers sums to target.
# 
# The same repeated number may be chosen from candidates unlimited number of
# times.
# 
# Note:
# 
# 
# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
# 
# 
# Example 1:
# 
# 
# Input: candidates = [2,3,6,7], target = 7,
# A solution set is:
# [
# ⁠ [7],
# ⁠ [2,2,3]
# ]
# 
# 
# Example 2:
# 
# 
# Input: candidates = [2,3,5], target = 8,
# A solution set is:
# [
# [2,2,2,2],
# [2,3,3],
# [3,5]
# ]
# 
# 
#
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
         count = [0] * len(candidates)
         remain = target
         curIndex = len(candidates)
         res = []
         candidates = sorted(candidates)
        
        # 寻找时先令较大元素数量最多, 然后枚举较小元素, 然后逐步减小较大元素的数量, 直至0
         while True:
             if remain != 0 and curIndex != 0:
                # 将前一个(较小)元素的数量设为最大
                 curIndex -= 1
                 count[curIndex] = remain // candidates[curIndex]
                 remain = remain % candidates[curIndex]
             else:
                 if remain == 0:
                    #找到一个答案
                     curRes = []
                     for i in range(len(candidates)):
                         curRes += [candidates[i]] * count[i]
                     res.append(curRes)
                 if curIndex == 0:
                    # 找到了开头(最小的元素)
                     if target // candidates[0] == count[0]:
                        # 最小的元素数量达到了最多, 查找结束
                         break
                    # 最小的元素的个数清0, 当前索引定位到最小的数量不为0的那个元素
                     remain += candidates[0] * count[0]
                     count[0] = 0
                     curIndex = 1
                     while count[curIndex] == 0:
                         curIndex += 1
                # 最小的数量不为0的这个元素的数量减1
                 remain += candidates[curIndex]
                 count[curIndex] -= 1

         return res

