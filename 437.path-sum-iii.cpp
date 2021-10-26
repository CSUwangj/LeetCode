/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
  int sum;
  int ans;
  void dfs(TreeNode* root, int cur, bool inPath) {
    if(!root) return;
    if(cur == root->val) ans += 1;
    if(!inPath) {
      dfs(root->left, cur, false);
      dfs(root->right, cur, false);
    }
    dfs(root->left, cur-root->val, true);
    dfs(root->right, cur-root->val, true);
  }
public:
  int pathSum(TreeNode* root, int sum) {
    if(!root) return 0;
    this->sum = sum;
    dfs(root, sum, false);
    return ans;
  }
};

// Accepted
// 126/126 cases passed (20 ms)
// Your runtime beats 66.65 % of cpp submissions
// Your memory usage beats 77.5 % of cpp submissions (15.7 MB)
// @lc code=end

