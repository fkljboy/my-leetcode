#
# @lc app=leetcode id=110 lang=python3
#
# [110] Balanced Binary Tree
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def height(self,root:TreeNode) -> int:
        if root == None: return 0
        return max(self.height(root.left),self.height(root.right))+1
    def isBalanced(self, root: TreeNode) -> bool:
        if root == None: return True
        return self.isBalanced(root.left) and self.isBalanced(root.right) and abs(self.height(root.left)-self.height(root.right))<=1

'''做法类似于c++解法