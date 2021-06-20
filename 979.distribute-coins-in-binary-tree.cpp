/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
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
  int answer;
  pair<int, int> solve(TreeNode *root) {
    if(!root) return {0, 0};
    int curNode = 1;
    int curCoin = root->val;
    auto [leftNode, leftCoin] = solve(root->left);
    auto [rightNode, rightCoin] = solve(root->right);
    // cout << answer << ' ' << leftNode << ' ' << rightNode << ' ' << leftCoin << ' ' << rightCoin << endl;
    answer += abs(leftNode - leftCoin) + abs(rightNode - rightCoin);
    return {curNode + leftNode + rightNode, curCoin + leftCoin + rightCoin};
  }
public:
  int distributeCoins(TreeNode* root) {
    answer = 0;
    solve(root);
    return answer;
  }
};
// @lc code=end

