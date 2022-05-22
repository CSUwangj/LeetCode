/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 */

// @lc code=start
class Solution {
  void traversal(TreeNode *&newCur, TreeNode *cur) {
    if(!cur) return;
    traversal(newCur, cur->left);
    newCur->right = new TreeNode(cur->val);
    newCur = newCur->right;
    traversal(newCur, cur->right);
  }
public:
  TreeNode* increasingBST(TreeNode* root) {
    TreeNode *newRoot = new TreeNode();
    TreeNode *tmp = newRoot;
    traversal(tmp, root);
    return newRoot->right;
  }
};

// Accepted
// 37/37 cases passed (3 ms)
// Your runtime beats 65.44 % of cpp submissions
// Your memory usage beats 19.7 % of cpp submissions (8 MB)
// @lc code=end
