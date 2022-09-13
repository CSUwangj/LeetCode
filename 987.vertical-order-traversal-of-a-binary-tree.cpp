/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */

// @lc code=start
class Solution {
  typedef struct _node {
    int y;
    int val;
    _node(int y, int val): y(y), val(val) {}
    bool operator<(const _node &a) {
      return this->y > a.y || (this->y == a.y && this->val < a.val);
    }
  } node;
  map<int, vector<node>> result;
  void traversal(TreeNode *root, int x, int y) {
    if(!root) return;
    result[x].push_back(node(y, root->val));
    traversal(root->left, x-1, y-1);
    traversal(root->right, x+1, y-1);
  }
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    traversal(root, 0, 0);
    vector<vector<int>> answer;
    for(auto &[_, nodes] : result) {
      answer.push_back(vector<int>());
      if(nodes.size() == 1) {
        answer.back().push_back(nodes.back().val);
      } else {
        sort(nodes.begin(), nodes.end());
        for(auto &node : nodes) answer.back().push_back(node.val);
      }
    }
    return answer;
  }
};

// Accepted
// 32/32 cases passed (10 ms)
// Your runtime beats 44.99 % of cpp submissions
// Your memory usage beats 72.74 % of cpp submissions (12.9 MB)
// @lc code=end

