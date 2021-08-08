/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    if(!root) return {};
    vector<vector<int>> answer;
    queue<Node*> q;
    q.push(root);
    while(q.size()) {
      int sz = q.size();
      vector<int> level;
      for(int _ = 0; _ < sz; ++_) {
        auto cur = q.front();
        q.pop();
        level.push_back(cur->val);
        for(auto child : cur->children) {
          q.push(child);
        }
      }
      answer.push_back(level);
    }
    return answer;
  }
};

// Accepted
// 38/38 cases passed (20 ms)
// Your runtime beats 86.78 % of cpp submissions
// Your memory usage beats 34.23 % of cpp submissions (11.9 MB)
// @lc code=end

