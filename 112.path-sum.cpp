/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
      if(NULL == root) return false;
         if(NULL == root->left && NULL == root->right) 
            return root->val - sum == 0;//若该判断式正确则输出true 反则输出false
         bool left = hasPathSum(root->left, sum - root->val);
         bool right = hasPathSum(root->right, sum - root->val);
         return left || right;
    }
};
/*深度优先遍历的递归解法：
首先判断root节点是否为空，如果为空则返回
若不为空则输出root
而后进入递归过程：进入原函数中，输入参数为
root的左节点，左树遍历完成后遍历最远端的
右节点。
深度优先遍历的迭代解法：
利用栈实现二叉树的深度优先遍历：
栈不空时，root指向栈顶元素，栈顶元素出栈；
若root 的右子树不空，则先压栈，若root左子树不空，则再压栈；
循环，栈顶元素出栈顺序即为深度优先遍历顺序
