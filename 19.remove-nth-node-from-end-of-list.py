#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head==None or head.next==None:
            return None
        f,s=head,head
        for i in range(n):
            f=f.next
        if f==None:
            return head.next
        while (f.next!=None):
            f=f.next
            s=s.next
        s.next=s.next.next
        return head
'''双指针法的Python实现
# @lc code=end

