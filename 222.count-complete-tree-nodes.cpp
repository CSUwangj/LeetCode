/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
  int height(TreeNode *root) {
    if(!root) return -1;
    int h = 0;
    while(root) {
      h += 1;
      root = root->left;
    }
    return h-1;
  }
public:
    int countNodes(TreeNode* root) {
      if(!root) return 0;
      int h = height(root);
      return h < 0 ? 0 :
                     height(root->right) == h - 1 ? (1 << h) + countNodes(root->right) :
                                                    (1 << (h - 1)) + countNodes(root->left);
    }
};

// Accepted
// 18/18 cases passed (30 ms)
// Your runtime beats 97.25 % of cpp submissions
// Your memory usage beats 93.85 % of cpp submissions (30.7 MB)
// @lc code=end

