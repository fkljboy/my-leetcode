#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
#
# https://leetcode.com/problems/longest-common-prefix/description/
#
# algorithms
# Easy (33.13%)
# Total Accepted:    426.1K
# Total Submissions: 1.3M
# Testcase Example:  '["flower","flow","flight"]'
#
# Write a function to find the longest common prefix string amongst an array of
# strings.
# 
# If there is no common prefix, return an empty string "".
# 
# Example 1:
# 
# 
# Input: ["flower","flow","flight"]
# Output: "fl"
# 
# 
# Example 2:
# 
# 
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
# 
# 
# Note:
# 
# All given inputs are in lowercase letters a-z.
# 
#
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
         maxStr, minStr = max(strs, default=""), min(strs, default="")
         for i in range(len(minStr)):
             if maxStr[i] != minStr[i]:
                 return minStr[:i]
         return minStr

''''
这是一种奇特的解法 利用了针对list的max函数和min函数，要知道在python中
每个字符串都是有大小的 即其acsll码的值的逐位进行比较  情况类似于“按照
名称首字母、次字母逐位进行排序，所以只要找到最大的和最小的两个的前缀字母
相同部分就是我们要找的结果
 def longestCommonPrefix(self, strs):
         if not strs: return ""
         ss = list(map(set, zip(*strs)))  set函数可以生成一个不含重复元素的元素集
         res = ""                         zip(*)是zip()的反向函数 ，意为解压
         for i, x in enumerate(ss):
             x = list(x)
             if len(x) > 1:
                break
             res = res + x[0]
         return res