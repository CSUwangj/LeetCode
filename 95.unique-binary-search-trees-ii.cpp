/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
TreeNode *copy(TreeNode *root) {
  if(!root) return nullptr;
  return new TreeNode(root->val, copy(root->left), copy(root->right));
}
class Solution {
  vector<TreeNode*> solve(int mask) {
    if(!mask) return {nullptr};
    vector<TreeNode*> answer;
    for(int i = 0; i < 8; ++i) {
      if(!(mask & (1 << i))) continue;
      auto left = solve(mask & ((1 << i) - 1));
      auto right = solve(mask & (((1 << 8) - 1) ^ ((1 << (i + 1)) - 1)));
      for(auto l : left) {
        for(auto r : right) {
          answer.push_back(new TreeNode(i + 1, copy(l), copy(r)));
        }
      }
    }
    return answer;
  }
public:
  vector<TreeNode*> generateTrees(int n) {
    return solve((1 << n) - 1);
  }
};

// Accepted
// 8/8 cases passed (20 ms)
// Your runtime beats 39.86 % of cpp submissions
// Your memory usage beats 5.85 % of cpp submissions (19.7 MB)
// @lc code=end

