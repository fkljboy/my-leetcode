#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
#
# https://leetcode.com/problems/length-of-last-word/description/
#
# algorithms
# Easy (32.18%)
# Total Accepted:    253.1K
# Total Submissions: 786.3K
# Testcase Example:  '"Hello World"'
#
# Given a string s consists of upper/lower-case alphabets and empty space
# characters ' ', return the length of last word in the string.
# 
# If the last word does not exist, return 0.
# 
# Note: A word is defined as a character sequence consists of non-space
# characters only.
# 
# Example:
# 
# Input: "Hello World"
# Output: 5
# 
# 
#
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
         cnt, tail = 0, len(s) - 1
         while tail >= 0 and s[tail] == ' ':
             tail -= 1
         while tail >= 0 and s[tail] != ' ':
             cnt += 1
             tail -= 1
         return cnt

