#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#
class Solution:
    def longestPalindrome(self, s: str) -> str:
        size = len(s)
        if size <= 1:
            return s
        # 二维 dp 问题
        # 状态：dp[l,r]: s[l:r] 包括 l，r ，表示的字符串是不是回文串
        # 设置为 None 是为了方便调试，看清楚代码执行流程
        dp = [[False for _ in range(size)] for _ in range(size)]

        longest_l = 1
        res = s[0]

        # 因为只有 1 个字符的情况在最开始做了判断
        # 左边界一定要比右边界小，因此右边界从 1 开始
        for r in range(1, size):
            for l in range(r):
                # 状态转移方程：如果头尾字符相等并且中间也是回文
                # 在头尾字符相等的前提下，如果收缩以后不构成区间（最多只有 1 个元素），直接返回 True 即可
                # 否则要继续看收缩以后的区间的回文性
                # 重点理解 or 的短路性质在这里的作用
                if s[l] == s[r] and (r - l <= 2 or dp[l + 1][r - 1]):
                    dp[l][r] = True
                    cur_len = r - l + 1
                    if cur_len > longest_l:
                        longest_l = cur_len
                        res = s[l:r + 1]
            # 调试语句
            # for item in dp:
            #     print(item)
            # print('---')
        return res
''''这是另一种思路的动态规划方案，与c++中的动态规划实现方案不同的是，这种思路采用了
统一化的思想，同样是滚雪球，将所有的状态都置为false，首先从最左端开始，只要可以使两端相等且中间只有一个数
或者没有数，即可判断该串是回文串，而后右界逐渐向右扩张，这种算法稳定的根源在于，想要判断一个
串是否为回文串 就要判断他的左右各进一位的子串是否为回文串，而这个工作在之前的滚雪球中已经完成了，因为
滚雪球是从小滚到大的，所以小的子串的状态是先于大的子串确定的。

