/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
  unordered_set<int> st;
public:
  bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    if(st.count(k - root->val)) return true;
    st.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};

// Accepted
// 422/422 cases passed (40 ms)
// Your runtime beats 60.78 % of cpp submissions
// Your memory usage beats 28.45 % of cpp submissions (39 MB)
// @lc code=end

