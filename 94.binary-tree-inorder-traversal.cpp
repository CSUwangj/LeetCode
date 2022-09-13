/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> answer;
    TreeNode *cur = root;
    while(cur) {
      if(!(cur->left)) {
        answer.push_back(cur->val);
        cur = cur->right;
      } else {
        TreeNode *left = cur->left;
        while(left->right && left->right != cur) {
          left = left->right;
        }
        if(left->right == cur) {
          answer.push_back(cur->val);
          left->right = nullptr;
          cur = cur->right;
        } else {
          left->right = cur;
          cur = cur->left;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 70/70 cases passed (6 ms)
// Your runtime beats 21.04 % of cpp submissions
// Your memory usage beats 39.59 % of cpp submissions (8.5 MB)
// @lc code=end

