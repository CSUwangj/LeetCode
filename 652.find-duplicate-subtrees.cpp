/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */

// @lc code=start
class Solution {
  unordered_map<string, vector<TreeNode*>> sameExpr;
  string visit(TreeNode *root) {
    if(!root) return "#";
    
    string result = to_string(root->val) + "," + visit(root->left) + "," + visit(root->right);
    sameExpr[result].push_back(root);
    return result;
  }
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    string tmp;
    visit(root);

    vector<TreeNode*> answer;
    for(const auto &[ _expr, roots] : sameExpr) {
      if(roots.size() > 1) answer.push_back(roots.front());
    }
    return answer;
  }
};

// Accepted
// 175/175 cases passed (27 ms)
// Your runtime beats 79.61 % of cpp submissions
// Your memory usage beats 38.15 % of cpp submissions (43.7 MB)
// @lc code=end

