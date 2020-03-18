#
# @lc app=leetcode id=12 lang=python3
#
# [12] Integer to Roman
#

# @lc code=start
class Solution:
    def intToRoman(self, num: int) -> str:
        value=[1000,900,500,400,100,90,50,40,10,9,5,4,1]
        strs=["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        res=""
        for i in range(len(value)):
            while num>=value[i]:
                res+=strs[i]
                num-=value[i]
        return res

# @lc code=end

