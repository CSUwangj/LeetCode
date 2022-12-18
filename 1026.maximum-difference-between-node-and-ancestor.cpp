/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int maxAncestorDiff(TreeNode* root, int mmin = INT_MAX, int mmax = INT_MIN) {
    // root node will not be nullptr by constraints
    if(!root) return mmax - mmin;
    mmin = min(mmin, root->val);
    mmax = max(mmax, root->val);
    return max(maxAncestorDiff(root->left, mmin, mmax), maxAncestorDiff(root->right, mmin, mmax));
  }
};

// Accepted
// 28/28 cases passed (3 ms)
// Your runtime beats 97.1 % of cpp submissions
// Your memory usage beats 97.32 % of cpp submissions (9.7 MB)
// @lc code=end
