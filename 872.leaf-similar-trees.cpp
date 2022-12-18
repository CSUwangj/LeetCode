/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 */

// @lc code=start
class Solution {
  void add(TreeNode* node, vector<int> &sequence) {
    if(!node->left && !node->right) {
      sequence.push_back(node->val);
    } else {
      if(node->left) add(node->left, sequence);
      if(node->right) add(node->right, sequence);
    }
  }
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> seq1, seq2;
    add(root1, seq1);
    add(root2, seq2);
    return seq1 == seq2;
  }
};

// Accepted
// 41/41 cases passed (7 ms)
// Your runtime beats 59.99 % of cpp submissions
// Your memory usage beats 63.83 % of cpp submissions (12.8 MB)
// @lc code=end

