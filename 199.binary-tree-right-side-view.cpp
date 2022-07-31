/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
  vector<int> answer;
  void traversal(TreeNode* root, int level) {
    if(!root) return;
    if(level > answer.size()) answer.push_back(root->val);
    traversal(root->right, level + 1);
    traversal(root->left, level + 1);
  }
public:
  vector<int> rightSideView(TreeNode* root) {
    traversal(root, 1);
    return move(answer);
  }
};

// Accepted
// 215/215 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 88.71 % of cpp submissions (11.9 MB)
// @lc code=end

