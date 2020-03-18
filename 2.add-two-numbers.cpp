/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=1;
        int len2=1;
        ListNode* p=l1;
        ListNode* q=l2;
        while (p->next!=NULL){
            len1++;
            p=p->next; //通过该方法迅速获得链表的长度
        }
        while (q->next!=NULL){
            len2++;
            q=q->next; //通过该方法迅速获得链表的长度
        }
        if (len1>len2){
            for (int i=0;i<len1-len2;i++){
                q->next=new ListNode(0);
                q=q->next;
            }
        }
        else{
            for (int i=0;i<len2-len1;i++){
                p->next=new ListNode(0);
                p=p->next;
            }
        }
        p=l1;
        q=l2;
        bool count=false;
        ListNode* l3=new ListNode(-1);
        ListNode* r=l3;
        int sum=0;
        // 进位问题的解决 一看就懂 
       while(p&&q){
            sum=count+q->val+p->val;
            r->next=new ListNode(sum%10);
            count=sum>=10?true:false;
            r=r->next;
            p=p->next;
            q=q->next;
        }
        //如果最高存在进位 就应该在存值链表中开辟新空间并将val置1
        if (count){
            r->next=new ListNode(1);
           // r=r->next;
        }
        return l3->next;
    }
};
/* 方法一 传统方法 如果两个链表的长度不一致 则
将短链表的尾端补零，使两个链表等长，然后按位相加 
但是要注意进位的技巧 进位的详细过程可以参考本代码 
比较经典 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* l3=new ListNode(-1);
         ListNode* p=l3;
         int sum=0;
         bool carry=false;
         while(l1||l2){
             sum=0;
             if (l1){
                 sum+=l1->val;
                 l1=l1->next;
             }
             if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if (carry==true){
                sum++;
            }
            l3->next=new ListNode(sum%10);
            l3=l3->naxt;
            carry=sum>=10?true:false;
         }
         if (carry==true){
             l3->next=new ListNode(1);
         }
         return p->next;
    }
};
/*方法二比较巧妙  不用补零 而是直接对每一位的和进行操作 如果大于10则进位 