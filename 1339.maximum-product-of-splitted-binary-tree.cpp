/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
class Solution {
  int sum = 0;
  int cur = 0;
  void add(TreeNode *root) {
    if(!root) return;
    sum += root->val;
    add(root->left);
    add(root->right);
  }
  int solve(TreeNode *root) {
    if(!root) return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    if(abs(left + right + root->val - sum / 2) < abs(cur - sum / 2)) {
      cur = left + right + root->val;
    }
    if (abs(left - sum / 2) < abs(cur - sum / 2)) {
      cur = left;
    }
    if (abs(right - sum / 2) < abs(cur - sum / 2)) {
      cur = right;
    }
    return left + right + root->val;
  }
public:
  int maxProduct(TreeNode* root) {
    add(root);
    solve(root);
    return 1LL * (sum - cur) * cur % MOD;
  }
};

// Accepted
// 54/54 cases passed (84 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 63.53 % of cpp submissions (77.5 MB)
// @lc code=end

