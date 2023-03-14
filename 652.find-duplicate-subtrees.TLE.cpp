/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */

// @lc code=start
class Solution {
  map<int, vector<TreeNode*>> sameVal;
  void visit(TreeNode *root) {
    if(!root) return;
    sameVal[root->val].push_back(root);
    visit(root->left);
    visit(root->right);
  }
  bool isSame(TreeNode *root1, TreeNode *root2) {
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->val != root2->val) return false;
    return isSame(root1->left, root2->left) && isSame(root2->right, root1->right);
  }
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    visit(root);
    vector<TreeNode*> answer;
    for(const auto &[_val, roots] : sameVal) {
      if(roots.size() < 2) continue;
      for(int i = 0; i < roots.size() - 1; ++i) {
        for(int j = i + 1; j < roots.size(); ++j) {
          if(!isSame(roots[i], roots[j])) continue;
          answer.push_back(roots[i]);
          break;
        }
      }
    }
    for(int i = 0; i + 1 < answer.size(); ++i) {
      for(int j = i + 1; j < answer.size(); ++j) {
        if(!isSame(answer[i], answer[j])) continue;
        answer.erase(answer.begin() + j);
        j -= 1;
      }
    }
    return answer;
  }
};
// @lc code=end

