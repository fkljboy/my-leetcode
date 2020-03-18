#
# @lc app=leetcode id=29 lang=python3
#
# [29] Divide Two Integers
#

# @lc code=start
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
         sign = (dividend > 0) ^ (divisor > 0)
         dividend = abs(dividend)
         divisor = abs(divisor)
         count = 0
        #把除数不断左移，直到它大于被除数
         while dividend >= divisor:
             count += 1
             divisor <<= 1
         result = 0
         while count > 0:
             count -= 1
             divisor >>= 1
             if divisor <= dividend:
                 result += 1 << count #这里的移位运算是把二进制（第count+1位上的1）转换为十进制
                 dividend -= divisor
         if sign: result = -result
         return result if -(1<<31) <= result <= (1<<31)-1 else (1<<31)-1 

''' 思路和c++版本的思路一致 区别在于c++版本的是从31开始往下减
而这个则是从1开始往上加
# @lc code=end
