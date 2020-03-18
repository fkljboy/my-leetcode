/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
              if (root == NULL) return 0;
        int left=minDepth(root->left),right=minDepth(root->right);
        return (left && right) ? 1+min(left,right):1+left+right;
    }
};
/* 需要留意的一点是如果一个节点的左右子树中有一个为空，这时的min函数会返回
一个零，但是这时计算最小子树时却要算另外一个不空的子树的深度，因为题意是计算
存在子树的节点的最小子树，如果都没有子树，那就不存在深度了，所以这压力需要加
一个判断，如果两个子树均存在，则和原来计算最深子树的方法一样，如果有一个子树
为空，则需在上一层的基础上加一，写成代码就是1+min左树和min右树（因为左树和右树
中必有一个为1另一个为0，所以等于变相的多加了一个1）
也可以直接判断两个子树是否为空而不是判断min函数是否为0 时间复杂度上更加简单
  if (root == NULL) return 0;
        TreeNode *left=root->left,*right=root->right;
        return (left && right) ? 1+min(minDepth(left),minDepth(right)):1+minDepth(left)+minDepth(right);
