/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    if(root->left || root->right) return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    return sum == root->val;
  }
};

// Accepted
// 117/117 cases passed (10 ms)
// Your runtime beats 90.94 % of cpp submissions
// Your memory usage beats 38.76 % of cpp submissions (21.4 MB)
// @lc code=end

