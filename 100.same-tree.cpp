/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
          if(p==q)return true;
        if(p && q&&p->val==q->val){
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
        else return false;
    }
};

/*if(p == NULL && q == NULL)
        return true;//都为空，相等。
    if(!p||!q)    //由于上面的判断不成立，则p，q至少有一个不为空
        return false;//一个空，一个不空，不相等
    if(p->val == q->val) //如果根节点相等
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);//判断左右子树是否都相等
    else 
        return false;
此方法通过前序遍历的方法逐一比较两个树的每一个键值 所以很好理解
两种方法的思路是一致的
        