class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n <= 1:
            return
        elif n == 2:
            nums[0], nums[1] = nums[1], nums[0]
            return
        i, j = n - 2, n - 1
        while i >= 0 and nums[i] >= nums[i+1]:
            i -= 1
        #找到这个数
        if i >= 0:
            while nums[i] >= nums[j]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        #找到这个数的替代数并实现替代
        nums[i+1:] = reversed(nums[i+1:])
        #将剩余的列表全部倒置

'''python 实现 