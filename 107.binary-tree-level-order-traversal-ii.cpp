/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*> q;
    vector<vector<int>> answer;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      vector<int> curLevel;
      for(int i = 0; i < sz; ++i) {
        auto node = q.front();
        q.pop();
        curLevel.push_back(node->val);
        if(node->left) {
          q.push(node->left);
        }
        if(node->right) {
          q.push(node->right);
        }
      }
      answer.push_back(curLevel);
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 34/34 cases passed (7 ms)
// Your runtime beats 51.45 % of cpp submissions
// Your memory usage beats 36.31 % of cpp submissions (12.6 MB)
// @lc code=end

