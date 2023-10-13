/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    queue<TreeNode*> Q;
    Q.push(root);
    int i = 0;
    while (!Q.empty()) {
      i++;
      int k = Q.size();
      for (int j = 0; j < k; ++j) {
        TreeNode* rt = Q.front();
        Q.pop();
        if (rt->left) Q.push(rt->left);
        if (rt->right) Q.push(rt->right);
        if (rt->left == NULL && rt->right == NULL) return i;
      }
    }
    return -1; //For the compiler thing. The code never runs here.
  }
};

// Accepted
// 52/52 cases passed (237 ms)
// Your runtime beats 99.27 % of cpp submissions
// Your memory usage beats 99.31 % of cpp submissions (144.4 MB)
// @lc code=end

