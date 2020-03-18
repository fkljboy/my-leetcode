/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> h;
        while(headA!=NULL){
            h.insert(headA);
            headA=headA->next;
        }
        while(headB!=NULL){
            if (h.count(headB)==1)
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};
/*方法一 类同于python解法

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if (headA==NULL||headA==NULL) return NULL;
       ListNode *a=headA,ListNode *b=headB;
        if (headA==NULL||headB==NULL) return NULL;
       ListNode *a=headA;
       ListNode *b=headB;
       int m=0;
        int n=0;
       while (a){
           m++;
           a=a->next;
       }
       while (b){
           n++;
           b=b->next;
       }
       a=headA;
       b=headB;
       if (m>n){
           for (int i=0;i<(m-n);i++){
               a=a->next;
           }
       }
       if (n>m) {
           for (int i=0;i<(n-m);i++){
               b=b->next;
           }
       }
    while(a&&b&&a!=b){
               a=a->next;
               b=b->next;
           }
           if (!a) return NULL;
           else return a;
    }
};
方法二：先计算各自单链表长度 然后从两个链表相同对应位置开始遍历
