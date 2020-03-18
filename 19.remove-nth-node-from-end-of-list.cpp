/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL || head->next==NULL) return NULL;
        ListNode* f=head,*s=head;
        for (int i=0;i<n;i++){
            f=f->next;
        }
        if(f==NULL) return head->next;
        while(f->next!=NULL){
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;
        return head;
    }
};
/*双指针法，设置一个快指针一个慢指针，然后快指针和慢指针之间隔了n，在设置完成之后
两个指针同时移动，直至快指针抵达尽头，这时慢指针所在的地方的下一个节点即为需要删除的
指针，操作即可。
// @lc code=end

