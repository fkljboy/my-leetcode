/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> list;
        while(head!=NULL){
            if (list.count(head))  return true;
            else list.insert(head);
            head=head->next;
        }
        return false;
    }
};
/* 方法一 哈希表法，将所有的节点指针存入哈希表中，一旦出现重复，这说明
出现了重复，则说明出现了链表环 返回true，如遍历链表中所有指针后没有出现
重复 则返回false


方法二 快慢指针法，设置两个指针，一个一次跳一步，一个一次跳两步，那么如果
存在环形链表，则最后快的指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL||head->next==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=head){
            if (fast->next==NULL||fast==NULL) return false;
            slow=slow->next;
            fast=fast->next->next;
        }
        return ture;
    }
};
