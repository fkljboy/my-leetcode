#
# @lc app=leetcode id=101 lang=python3
#
# [101] Symmetric Tree
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def ismirror(p,q):
            if not p and not q:
                return True
            elif p is not None and q is not None:
                if p.val == q.val:
                    return ismirror(p.left, q.right) and ismirror(p.right, q.left)
                else:
                    return False
            else:
                return False
        return ismirror(root,root)

