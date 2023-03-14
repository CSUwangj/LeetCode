/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
    // cout << root->val << ' ' << answer << ' ';
    if(st.size()) {
      auto lessIt = st.upper_bound(root->val);
      if(lessIt != st.begin()) {
        --lessIt;
        // cout << "less " << *lessIt << ' ';
        answer = min(answer, root->val - *lessIt);
      }
      auto moreOrEqualIt = st.lower_bound(root->val);
      if(moreOrEqualIt != st.end()) {
        // cout << "more " << *moreOrEqualIt;
        answer = min(answer, *moreOrEqualIt - root->val);
      }
    }
    // cout << endl;
    st.insert(root->val);
    solve(root->left, st);
    solve(root->right, st);
  }
public:
  int minDiffInBST(TreeNode* root) {
    set<int> st;
    solve(root, st);
    return answer;
  }
};

// Accepted
// 48/48 cases passed (3 ms)
// Your runtime beats 67.12 % of cpp submissions
// Your memory usage beats 6.62 % of cpp submissions (11.6 MB)
// @lc code=end

