/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
class Solution {
  unordered_map<TreeNode*, int> put;
  unordered_map<TreeNode*, int> covered;
  unordered_map<TreeNode*, int> blank;
  void solve(TreeNode *root) {
    if(!root) return;
    solve(root->left);
    solve(root->right);
    put[root] = 1 + min({
                    covered[root->left],
                    put[root->left],
                    blank[root->left]
                  }) + min({
                    covered[root->right],
                    put[root->right],
                    blank[root->right]
                  });
    covered[root] = min({put[root->left] + covered[root->right],
                         put[root->right] + covered[root->left],
                         put[root->left] + put[root->right]});
    blank[root] = covered[root->left] + covered[root->right];
  }
public:
  int minCameraCover(TreeNode* root) {
    put[nullptr] = 10000;
    solve(root);
    return min(put[root], covered[root]);
  }
};

// Accepted
// 171/171 cases passed (36 ms)
// Your runtime beats 9.71 % of cpp submissions
// Your memory usage beats 5.1 % of cpp submissions (28.2 MB)
// @lc code=end

