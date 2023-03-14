/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return {};
    stack<TreeNode*> stackForth;
    stack<TreeNode*> stackBack;
    stackForth.push(root);
    vector<vector<int>> answer;
    while(stackForth.size()) {
      vector<int> result;
      while(stackForth.size()) {
        auto cur = stackForth.top();
        stackForth.pop();
        result.push_back(cur->val);
        if(cur->left) stackBack.push(cur->left);
        if(cur->right) stackBack.push(cur->right);
      }
      answer.push_back(result);
      if(!stackBack.size()) break;
      result.clear();
      while(stackBack.size()) {
        auto cur = stackBack.top();
        stackBack.pop();
        result.push_back(cur->val);
        if(cur->right) stackForth.push(cur->right);
        if(cur->left) stackForth.push(cur->left);
      }
      answer.push_back(result);
    }
    return answer;
  }
};

// Accepted
// 33/33 cases passed (3 ms)
// Your runtime beats 73.66 % of cpp submissions
// Your memory usage beats 48.4 % of cpp submissions (12.2 MB)
// @lc code=end
