/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool helper(TreeNode *left, TreeNode *right) {
    if(!left && !right) return true;
    if(!left || !right) return false;
    if(left->val != right->val) return false;
    return helper(left->left, right->right) && helper(left->right, right->left);
  }
public:
  bool isSymmetric(TreeNode* root) {
    return helper(root, root);
  }
};

// Accepted
// 197/197 cases passed (8 ms)
// Your runtime beats 50.17 % of cpp submissions
// Your memory usage beats 17.95 % of cpp submissions (16.5 MB)
// @lc code=end
