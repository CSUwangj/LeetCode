/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
  TreeNode *construct(vector<int> &nums, int begin, int end) {
    if(begin > end) return nullptr;
    int mid = (begin + end) >> 1;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = construct(nums, begin, mid - 1);
    root->right = construct(nums, mid + 1, end);
    return root;
  }
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int len = nums.size();
    return construct(nums, 0, len - 1);
  }
};

// Accepted
// 31/31 cases passed (8 ms)
// Your runtime beats 95.55 % of cpp submissions
// Your memory usage beats 75.67 % of cpp submissions (21.4 MB)
// @lc code=end

