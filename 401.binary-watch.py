#
# @lc app=leetcode id=401 lang=python3
#
# [401] Binary Watch
#
# https://leetcode.com/problems/binary-watch/description/
#
# algorithms
# Easy (45.10%)
# Total Accepted:    61.3K
# Total Submissions: 135.8K
# Testcase Example:  '0'
#
# A binary watch has 4 LEDs on the top which represent the hours (0-11), and
# the 6 LEDs on the bottom represent the minutes (0-59).
# Each LED represents a zero or one, with the least significant bit on the
# right.
# 
# For example, the above binary watch reads "3:25".
# 
# Given a non-negative integer n which represents the number of LEDs that are
# currently on, return all possible times the watch could represent.
# 
# Example:
# Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
# "0:08", "0:16", "0:32"]
# 
# 
# Note:
# 
# The order of output does not matter.
# The hour must not contain a leading zero, for example "01:00" is not valid,
# it should be "1:00".
# The minute must be consist of two digits and may contain a leading zero, for
# example "10:2" is not valid, it should be "10:02".
# 
# 
#
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
          ret = []
         for hour in range(12):
             for minute in range(60):
                 if (bin(hour) + bin(minute)).count('1') == num:
                     ret.append('%d:%02d' % (hour, minute))           
         return ret

'''需要注意在python中 bin函数可以将int型的十进制数据转换为 二进制的字符串