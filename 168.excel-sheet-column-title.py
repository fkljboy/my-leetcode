#
# @lc app=leetcode id=168 lang=python3
#
# [168] Excel Sheet Column Title
#
class Solution:
    def convertToTitle(self, n: int) -> str:
        res = ""
        while n:
            n, y = divmod(n, 26) 
            if y == 0:
                n -= 1
                y = 26
            res = chr(y + 64) + res
        return res


