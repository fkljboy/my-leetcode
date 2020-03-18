#
# @lc app=leetcode id=6 lang=python3
#
# [6] ZigZag Conversion
#
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1 :
            return s
        res=["" for i in range(numRows)]
        crow,edge=0,-1
        for i in s:
            res[crow]+=i
            if (crow==0 or numRows-1==crow): edge=-edge
            crow+=edge
        return "".join(res)
''' 这里用到了join()函数，该函数的用法是把原有序列的字符串用指定的符号连接为一个
新的字符串 很强  其他的思路和c++是一样的-