#
# @lc app=leetcode id=112 lang=python3
#
# [112] Path Sum
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
          if not root: return False
          t = sum - root.val
          if not root.left and not root.right:
            return t == 0
          return self.hasPathSum(root.left, t) or self.hasPathSum(root.right, t)

'''python的解法类似于c++，一般来说 需要调用类中变量（在本题中调用的是root.left,root.right）的
函数，在前面一定要前缀self.而没有调用的则称为“类方法”