/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
  int goodNodes(TreeNode* root, int X = INT_MIN) {
    if(!root) return 0;
    if(root->val >= X) {
      return 1 + goodNodes(root->left, root->val) + goodNodes(root->right, root->val);
    } else {
      return goodNodes(root->left, X) + goodNodes(root->right, X);
    }
  }
};

// Accepted
// 63/63 cases passed (96 ms)
// Your runtime beats 99.23 % of cpp submissions
// Your memory usage beats 6.64 % of cpp submissions (86.6 MB)
// @lc code=end

