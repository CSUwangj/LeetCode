/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
  int len;
  TreeNode* solve(vector<int> &arr, int &index, int min = INT_MIN, int max = INT_MAX) {
    if(index == len) return nullptr;
    if(arr[index] < min || arr[index] > max) return nullptr;
    int val = arr[index];
    auto node = new TreeNode(val);
    index += 1;
    node->left = solve(arr, index, min, val);
    node->right = solve(arr, index, val, max);
    return node;
  }
public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    len = preorder.size();
    int index = 0;
    return solve(preorder, index);
  }
};

// Accepted
// 110/110 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 43.07 % of cpp submissions (13.8 MB)
// @lc code=end

