/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
  bool parity[10] = {0};
  int answer = 0;
  int odd = 0;
  void helper(TreeNode *root) {
    parity[root->val] ^= 1;
    if(parity[root->val]) odd += 1;
    else odd -= 1;
    if(!(root->left) && !(root->right)) answer += (odd < 2);
    if(root->left) helper(root->left);
    if(root->right) helper(root->right);
    if(parity[root->val]) odd -= 1;
    else odd += 1;
    parity[root->val] ^= 1;
  }
public:
  int pseudoPalindromicPaths (TreeNode* root) {
    helper(root);
    return answer;
  }
};

// Accepted
// 56/56 cases passed (675 ms)
// Your runtime beats 38.56 % of cpp submissions
// Your memory usage beats 92.41 % of cpp submissions (179.1 MB)
// @lc code=end

