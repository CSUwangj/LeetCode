/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
  int answer = INT_MAX;
  void solve(TreeNode* root, set<int> &st) {
    if(!root) return;
    if(st.size()) {
      auto lessIt = st.upper_bound(root->val);
      if(lessIt != st.begin()) {
        --lessIt;
        answer = min(answer, root->val - *lessIt);
      }
      auto moreOrEqualIt = st.lower_bound(root->val);
      if(moreOrEqualIt != st.end()) {
        answer = min(answer, *moreOrEqualIt - root->val);
      }
    }
    st.insert(root->val);
    solve(root->left, st);
    solve(root->right, st);
  }
public:
  int getMinimumDifference(TreeNode* root) {
    set<int> st;
    solve(root, st);
    return answer;
  }
};

// Accepted
// 188/188 cases passed (27 ms)
// Your runtime beats 30.22 % of cpp submissions
// Your memory usage beats 5.25 % of cpp submissions (29.5 MB)
// @lc code=end

