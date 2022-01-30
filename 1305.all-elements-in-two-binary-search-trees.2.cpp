/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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
  void inorder(TreeNode *root, vector<int> &result) {
    if(!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
  }
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> answer;
    inorder(root1, answer);
    inorder(root2, answer);
    sort(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 48/48 cases passed (100 ms)
// Your runtime beats 99.95 % of cpp submissions
// Your memory usage beats 91.67 % of cpp submissions (84.4 MB)
// @lc code=end
