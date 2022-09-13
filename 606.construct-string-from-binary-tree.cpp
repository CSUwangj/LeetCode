/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
 */

// @lc code=start
class Solution {
public:
  string tree2str(TreeNode* root) {
    if(!root) return "";
    auto current = to_string(root->val);
    if(root->left || root->right) current += "(" + tree2str(root->left) + ")";
    if(root->right) current += "(" + tree2str(root->right) + ")";
    return current;
  }
};

// Accepted
// 160/160 cases passed (53 ms)
// Your runtime beats 25.89 % of cpp submissions
// Your memory usage beats 23.79 % of cpp submissions (53.9 MB)
// @lc code=end

