/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
    if(!root) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(!root->val && !root->left && !root->right) return nullptr;
    return root;
  }
};

// Accepted
// 30/30 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 21.01 % of cpp submissions (8.8 MB)
// @lc code=end

