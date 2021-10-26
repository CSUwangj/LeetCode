/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
      if(!root) return 0;
      TreeNode* left = root;
      TreeNode* right = root;
      int count = 0;
      while(left && right) {
        left = left->left;
        right = right->right;
        count += 1;
      }
      if(!left && !right) return (1 << count) - 1;
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Accepted
// 18/18 cases passed (62 ms)
// Your runtime beats 13.83 % of cpp submissions
// Your memory usage beats 21.46 % of cpp submissions (30.9 MB)
// @lc code=end

