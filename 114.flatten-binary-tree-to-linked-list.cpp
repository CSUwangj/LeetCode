/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
  TreeNode* rightMost = nullptr;
public:
  void flatten(TreeNode* root) {
    if(!root) return;
    rightMost = root;
    if(root->left) {
      flatten(root->left);
      rightMost->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }
    flatten(rightMost->right);
  }
};
// @lc code=end

