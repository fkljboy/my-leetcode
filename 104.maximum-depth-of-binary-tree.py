#
# @lc app=leetcode id=104 lang=python3
#
# [104] Maximum Depth of Binary Tree
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
'''
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        count=1
        return count+=max(self.maxDepth(root.left),self.maxDepth(root.right))
'''
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return max(self.maxDepth(root.left),self.maxDepth(root.right))+1
        '''做法和c++的方法类似