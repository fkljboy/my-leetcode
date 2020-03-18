/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.24%)
 * Total Accepted:    533.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(-1), *cur = dummyHead, **selected;
        while (l1 || l2) {
        if (!l1) selected = &l2;
        else if (!l2) selected = &l1;
        else if (l1->val < l2->val) selected = &l1;
        else selected = &l2;
        cur->next = *selected;
        *selected = (*selected)->next;
        cur = cur->next;
    }
    return dummyHead->next; 
    }
};
/* 这里需要熟悉链表Listnode 的特性 ListNode *dummyHead = new ListNode(-1)指的是将指针dmmyhead的初值定为-1 而后再定义一个cur指针从而
构建了链表。在l1和l2都不为空的时候将selected指向l2&l1的地址，而后对l1和l2的val进行比较，将较小的一个作为链表的表头
