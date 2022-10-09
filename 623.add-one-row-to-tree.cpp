/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
  TreeNode* addOneRow(TreeNode* root, int v, int d, bool left = true) {
    if(d == 1) {
      TreeNode *newRoot = new TreeNode(v);
      if(left) newRoot->left = root;
      else newRoot->right = root;
      return newRoot;
    }
    if(!root) return nullptr;
    root->left = addOneRow(root->left, v, d-1, true);
    root->right = addOneRow(root->right, v, d-1, false);
    return root;
  }
};

// Accepted
// 109/109 cases passed (23 ms)
// Your runtime beats 85.7 % of cpp submissions
// Your memory usage beats 62.88 % of cpp submissions (25 MB)
// @lc code=end

