/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
class Solution {
  int answer;
  int pathLength(TreeNode * root) {
    if(!root) return 0;
    int left = pathLength(root->left);
    int right = pathLength(root->right);
    answer = max(answer, left + right);
    return 1 + max(left, right);
  }
public:
  int diameterOfBinaryTree(TreeNode* root) {
    pathLength(root);
    return answer;
  }
};

// Accepted
// 104/104 cases passed (14 ms)
// Your runtime beats 37.05 % of cpp submissions
// Your memory usage beats 64.86 % of cpp submissions (20.3 MB)
// @lc code=end

