/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 */

// @lc code=start
class Solution {
public:
  int sumOfLeftLeaves(TreeNode* root) {
    if(!root) return 0;
    int val = 0;
    if(root->left && !root->left->left && !root->left->right) {
      return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};

// Accepted
// 100/100 cases passed (4 ms)
// Your runtime beats 71.52 % of cpp submissions
// Your memory usage beats 44.54 % of cpp submissions (13.5 MB)
// @lc code=end

