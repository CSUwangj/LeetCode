/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
  int sumRootToLeaf(TreeNode* root, int cur = 0) {
    if(!root) return 0;
    cur = ((cur << 1) | root->val);
    if(!root->left && !root->right) return cur;
    return sumRootToLeaf(root->left, cur) + sumRootToLeaf(root->right, cur);
  }
};

// Accepted
// 63/63 cases passed (4 ms)
// Your runtime beats 87.29 % of cpp submissions
// Your memory usage beats 29.55 % of cpp submissions (16.8 MB)
// @lc code=end
