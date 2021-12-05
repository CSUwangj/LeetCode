/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  pair<int, int> solve(TreeNode *root) {
    if(!root) {
      return {0, 0};
    }
    auto [maxLeft, maxNotRobLeft] = solve(root->left);
    auto [maxRight, maxNotRobRight] = solve(root->right);
    int maxRob = root->val + maxNotRobLeft + maxNotRobRight;
    int maxNotRob = maxLeft + maxRight;
    return {max(maxRob, maxNotRob), maxNotRob};
  }
public:
  int rob(TreeNode* root) {
    return solve(root).first;
  }
};

// Accepted
// 124/124 cases passed (4 ms)
// Your runtime beats 99.42 % of cpp submissions
// Your memory usage beats 70.99 % of cpp submissions (22.2 MB)
// @lc code=end
