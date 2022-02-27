/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
  int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

// Accepted
// 39/39 cases passed (7 ms)
// Your runtime beats 83.32 % of cpp submissions
// Your memory usage beats 56.35 % of cpp submissions (18.9 MB)
// @lc code=end
