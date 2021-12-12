/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
 */

auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  pair<int, int> solve(TreeNode *root) {
    if(!root) return {0, 0};
    auto [leftTilt, leftSum] = solve(root->left);
    auto [rightTilt, rightSum] = solve(root->right);
    return {leftTilt + rightTilt + abs(leftSum - rightSum), leftSum + root->val + rightSum};
  }
public:
  int findTilt(TreeNode* root) {
    return solve(root).first;
  }
};

// Accepted
// 77/77 cases passed (24 ms)
// Your runtime beats 30.2 % of cpp submissions
// Your memory usage beats 6.17 % of cpp submissions (24.1 MB)
// @lc code=end
