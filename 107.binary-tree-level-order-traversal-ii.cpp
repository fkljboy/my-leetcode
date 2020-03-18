/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;//结果
        if(root == NULL) return res;
        queue<TreeNode *> q[2];//两个队列轮流使用
        int cur = 0;
        q[cur].push(root);
        while(!q[cur].empty()){
            vector<int> row;
            while(!q[cur].empty()){
                TreeNode *node = q[cur].front();//将元素依次出队
                row.push_back(node->val);//将值放入行向量
                q[cur].pop();//出队
                if(node->left)  q[!cur].push(node->left);//如果左右子节点有孩子，就加入到另一个队列
                if(node->right) q[!cur].push(node->right);
            }
            cur = !cur;//两个队列轮流使用
            res.insert(res.begin(),row);//将行向量插入到最前面
        }
        return res;
    }
};
/* 双队列解决层遍历问题的感悟，首先，定义两个队列，交替使用，可以理解为一个
队列是给另外一个队列存放其所有孩子节点的队列（即下一层的遍历） 然后从根节点
开始遍历，遍历的方法是，先把根节点放入队列，然后将队列中的值依次出队，并存入
一个动态数组中，然后将该值从队列中删除，接下来考察该值的孩子节点，并将其孩子
节点存入第二个队列中，在遍历了这一层所有的节点以后，该队列就已经清空了，这时候
切换操作另一个队列，并重复上述的步骤，一次循环往复。需要注意的是需要将一次完整的
遍历的结果保存到最初定义的那个动态数组中，并在一次遍历结束后将该数组插入到我们
最后需要的那个vector的最前面，从而达到逐层遍历的目的。
