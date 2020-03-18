#
# @lc app=leetcode id=107 lang=python3
#
# [107] Binary Tree Level Order Traversal II
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ok = [root]
        res = []
        while ok:
            ok_tmp = []
            layer = []
            for node in ok:
                if not node:
                    continue
                ok_tmp.append(node.left)
                ok_tmp.append(node.right)
                layer.append(node.val)
            if layer:
                res.append(layer)
            ok = ok_tmp
        return res[::-1]
'''遍历二叉树的感悟：队列不是必须的，在python中使用普通的列表也可以
解决问题，必要的是一个辅助用的数组，需要在一次遍历以后实现两个数组的
互换，至于先进先出的问题，用队列是最方便的，但是使用循环同样可以实现
先进先出，这是可以实现的
