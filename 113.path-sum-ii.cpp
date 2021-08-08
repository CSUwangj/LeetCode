/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
  void solve(
    vector<vector<int>> &answer,
    vector<int> &container,
    TreeNode *root,
    int rest
  ) {
    if(!root) return;
    container.push_back(root->val);
    rest -= root->val;
    if(!rest && !root->left && !root->right) {
      answer.push_back(container);
    } else {
      solve(answer, container, root->left, rest);
      solve(answer, container, root->right, rest);
    }
    container.pop_back();
  }
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> answer;
    vector<int> temp;
    solve(answer, temp, root, targetSum);
    return move(answer);
  }
};

// Accepted
// 115/115 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 81.42 % of cpp submissions (19.8 MB)
// @lc code=end

