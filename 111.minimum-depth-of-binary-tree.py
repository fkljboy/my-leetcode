#
# @lc app=leetcode id=111 lang=python3
#
# [111] Minimum Depth of Binary Tree
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root:
            if root.left and root.right:
                return 1+min(self.minDepth(root.left),self.minDepth(root.right))
            elif root.left:
                return 1+self.minDepth(root.left)
            elif root.right:
                return 1+self.minDepth(root.right)
            else:
                return 1
        else:
            return 0
'''解法类似于c++的解法
注意c++中语法和python的区别，注意类方法调用要用self.作为前缀
