#
# @lc app=leetcode id=171 lang=python3
#
# [171] Excel Sheet Column Number
#
class Solution:
    def titleToNumber(self, s: str) -> int:
        ans =0
        for x in s :
            ans *=26
            ans+=ord(x)-ord('A')+1
        return ans
        

