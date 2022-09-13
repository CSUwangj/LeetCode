/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  vector<pair<int, double>> count;
  void traversal(TreeNode *root, int level) {
    if(!root) return;
    if(count.size() <= level) count.push_back(make_pair(0, 0));
    count[level].first += 1;
    count[level].second += root->val;
    traversal(root->left, level + 1);
    traversal(root->right, level + 1);
  }
public:
  vector<double> averageOfLevels(TreeNode* root) {
    traversal(root, 0);
    vector<double> answer;
    for(auto [cnt, sum] : count) {
      answer.push_back(sum / cnt);
    }
    return move(answer);
  }
};

// Accepted
// 66/66 cases passed (27 ms)
// Your runtime beats 44.2 % of cpp submissions
// Your memory usage beats 72.83 % of cpp submissions (22.5 MB)
// @lc code=end

