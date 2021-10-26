/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
  TreeNode *parents[2];
  int depths[2];
  int nodes[2];
  void find(TreeNode *parent, TreeNode *cur, int depth = 0) {
    if(!cur) return;
    for(int i = 0; i < 2; ++i) {
      if(cur->val == nodes[i]) {
        parents[i] = parent;
        depths[i] = depth;
      }
    }
    find(cur, cur->left, depth + 1);
    find(cur, cur->right, depth + 1);
  }
public:
  bool isCousins(TreeNode* root, int x, int y) {
    nodes[0] = x;
    nodes[1] = y;
    find(nullptr, root);
    return depths[0] == depths[1] && parents[0] != parents[1];
  }
};

// Accepted
// 105/105 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 75.59 % of cpp submissions (11 MB)
// @lc code=end

