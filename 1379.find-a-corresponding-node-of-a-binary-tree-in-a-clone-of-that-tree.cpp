/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 */

// @lc code=start
class Solution {
public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if(!original) return nullptr;
    if(original == target) return cloned;
    TreeNode *left = getTargetCopy(original->left, cloned->left, target);
    if(left) return left;
    TreeNode *right = getTargetCopy(original->right, cloned->right, target);
    if(right) return right;
    return nullptr;
  }
};

// Accepted
// 56/56 cases passed (599 ms)
// Your runtime beats 70.48 % of cpp submissions
// Your memory usage beats 81.24 % of cpp submissions (163.8 MB)
// @lc code=end

