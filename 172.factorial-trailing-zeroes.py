#
# @lc app=leetcode id=172 lang=python3
#
# [172] Factorial Trailing Zeroes
#
class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        
        while n >= 5:
            res += n // 5
            n //= 5
        
        return res

