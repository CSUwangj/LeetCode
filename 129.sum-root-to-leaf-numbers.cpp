/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
  int sumNumbers(TreeNode* root, int cur = 0) {
    if(!root) return 0;
    cur = cur * 10 + root->val;
    if(root->left || root->right) return sumNumbers(root->left, cur) + sumNumbers(root->right, cur);
    return cur;
  }
};

// Accepted
// 108/108 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.09 % of cpp submissions (9.1 MB)
// @lc code=end

