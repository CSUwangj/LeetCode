/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
  vector<int> preorderTraversal(TreeNode* root) {
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
          left->right = nullptr;
          cur = cur->right;
        } else {
          left->right = cur;
          answer.push_back(cur->val);
          cur = cur->left;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 69/69 cases passed (6 ms)
// Your runtime beats 20.93 % of cpp submissions
// Your memory usage beats 44.83 % of cpp submissions (8.4 MB)
// @lc code=end

