/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
  TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
  }
};

// Accepted
// 77/77 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 79.47 % of cpp submissions (9.7 MB)
// @lc code=end

