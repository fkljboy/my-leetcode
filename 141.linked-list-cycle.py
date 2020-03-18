#
# @lc app=leetcode id=141 lang=python
#
# [141] Linked List Cycle
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head==None:
            return False
        hs={head}
        head=head.next
        while head:
            if head in hs:
                return True
            else:
                hs.add(head)
                head=head.next
        return False 
'''此为python的容器法，使用一个容器来保留唯一的指针，如果出现重复则说明出现
环

方法二：快慢指针法
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head==None or head.next==None:
            return False
        f=head.next
        s=head
        while f!=s:
            if f==None or f.next==None:
                return False
            else:
                s=s.next
                f=f.next.next
        return True 
思路与c++的思路一致
