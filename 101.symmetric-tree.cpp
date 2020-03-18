/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
     bool isSymmetric(TreeNode* root) 
    {
        return ismirror(root,root);
    }
    
    bool ismirror(TreeNode* p,TreeNode* q){
        if(!p&&!q)//都为NULL
            return true;
        if(!p||!q)//有一个为NULL
            return false;
        if(p->val==q->val)
            return ismirror(p->left,q->right)&&ismirror(p->right,q->left);
        return false;
        
    }
};

/*和上题类似，唯一不同的点是此题需要加入一个递归函数并且判断一个子树的相反的
子树是否相等。