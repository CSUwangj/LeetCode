/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int sum = 0;
  int height = 0;
  void solve(TreeNode *root, int level) {
    if(!root) return;
    if(level > height) {
      sum = 0;
      height = level;
    }
    sum += (level == height) * root->val;
    solve(root->left, level + 1);
    solve(root->right, level + 1);
  }
public:
  int deepestLeavesSum(TreeNode* root) {
    solve(root, 0);
    return sum;
  }
};

// Accepted
// 35/35 cases passed (125 ms)
// Your runtime beats 57.56 % of cpp submissions
// Your memory usage beats 76.5 % of cpp submissions (59.8 MB)
// @lc code=end
