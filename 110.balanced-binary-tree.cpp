/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    //这个ReturnNode是参考我描述的递归套路的第二步：思考返回值是什么
    //一棵树是BST等价于它的左、右俩子树都是BST且俩子树高度差不超过1
    //因此我认为返回值应该包含当前树是否是BST和当前树的高度这两个信息
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(abs(countFloor(root->left)-countFloor(root->right))>1)
            return false;
        else
        {
            if(isBalanced(root->left) && isBalanced(root->right))
            {
            return true;
            }
            else
                return false;
        }
        }
    int countFloor(TreeNode* root)
    {//计算树层高
                if(!root)
                    return 0;
                return 1+max(countFloor(root->left),countFloor(root->right));
    }        
};
/*就是递归的三部曲：
1.找终止条件：什么时候递归到头了？此题自然是root为空的时候，空树当然是平衡的。
2.思考返回值，每一级递归应该向上返回什么信息？参考代码中的注释。
3.单步操作应该怎么写？因为递归就是大量的调用自身的重复操作，因此从宏观上考虑，
只用想想单步怎么写就行了，左树和右树应该看成一个整体，即此时树一共三个节点：
root，root.left，root.right。

