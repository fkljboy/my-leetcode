#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input array is sorted
#
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        L=0
        H=len(numbers)-1
        while L<H:
            if numbers[L]+numbers[H]>target:
                H=H-1
            elif numbers[L]+numbers[H]<target:
                L=L+1
            else:
                return [L+1,H+1]
        return [-1,-1]

''' 
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d = {}
        for i in range(len(numbers)):
            res = target - numbers[i]
            if numbers[i] in d:
                return [d[numbers[i]],i+1]
            else: 
                d[res] = i + 1
方法二 类似于c++的哈希表法，将所有的数据保存在一个字典中，然后通过遍历
   匹配得到最终的结果