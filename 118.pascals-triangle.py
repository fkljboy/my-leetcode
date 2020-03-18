#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
#
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = []
        for i in range(numRows):
            now = [1]*(i+1)
            if i >= 2:
                for n in range(1,i):
                    now[n] = pre[n-1]+pre[n]
            result += [now]
            pre = now
        return result

'''先让所有的now的值都为1 这就免除了专门去定义开头和末尾值的过程
之后的做法和c++类似但是要注意两者语法的区别，注意python中for循环
范围的限定