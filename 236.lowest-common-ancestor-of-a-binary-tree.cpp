/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q) return root;
    if(!root) return nullptr;
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    if(!left && !right) return nullptr;
    if(!left) return right;
    return left;
  }
};

// Accepted
// 31/31 cases passed (30 ms)
// Your runtime beats 32.18 % of cpp submissions
// Your memory usage beats 25.3 % of cpp submissions (14.3 MB)
// @lc code=end

