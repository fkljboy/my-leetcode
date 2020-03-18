/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int count = 1;
        return count += std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

/* 递归 递归的思想是 加入一个比较过程，把每条子树的长度都算出来，然后
两两比较 最后找到最长的一个子树