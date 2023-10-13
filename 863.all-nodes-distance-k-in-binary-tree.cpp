/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  void buildGraph(TreeNode *root, vector<vector<int>> &neighbors) {
    int val = root->val;
    if(root->left) {
      neighbors[val].push_back(root->left->val);
      neighbors[root->left->val].push_back(val);
      buildGraph(root->left, neighbors);
    }
    if(root->right) {
      neighbors[val].push_back(root->right->val);
      neighbors[root->right->val].push_back(val);
      buildGraph(root->right, neighbors);
    }
  }
  void solve(
    int current,
    int parent,
    int k,
    vector<int> &answer,
    const vector<vector<int>> &neighbors
  ) {
    if(!k) {
      answer.push_back(current);
      return;
    }
    for(auto next : neighbors[current]) {
      if(parent == next) continue;
      solve(next, current, k - 1, answer, neighbors);
    }
  }
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<vector<int>> neighbors(501);
    buildGraph(root, neighbors);
    vector<int> answer;
    solve(target->val, -1, k, answer, neighbors);
    return answer;
  }
};

// Accepted
// 57/57 cases passed (9 ms)
// Your runtime beats 38.57 % of cpp submissions
// Your memory usage beats 5.12 % of cpp submissions (16.9 MB)
// @lc code=end

