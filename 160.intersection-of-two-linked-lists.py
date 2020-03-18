#
# @lc app=leetcode id=160 lang=python
#
# [160] Intersection of Two Linked Lists
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        hs=[]
        while headA:
            hs.add(headA)
            headA=headA.next
        while headB:
            if headB in hs:
                return headB
            headB=headB.next
        return None
''''方法一 哈希表法 将其中任意一个链表的每一个节点的地址信息
存入集合中 然后遍历另外一个链表 如果该链表的某个地址值在集合
中存在，这说明该地址为两链表汇合处