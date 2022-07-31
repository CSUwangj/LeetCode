/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
  TreeNode *build(
    vector<int>& preorder,
    int preBegin,
    int preEnd,
    vector<int>& inorder,
    int inBegin,
    int inEnd
  ) {
    if(preBegin > preEnd) return nullptr;
    int rootIdx = -1;
    for(int i = inBegin; i <= inEnd; ++i) {
      if(inorder[i] == preorder[preBegin]) {
        rootIdx = i;
        break;
      }
    }
    int offset = rootIdx - inBegin;
    TreeNode *root = new TreeNode(preorder[preBegin]);
    root->left = build(preorder, preBegin + 1, preBegin + offset, inorder, inBegin, inBegin + offset - 1);
    root->right = build(preorder, preBegin + offset + 1, preEnd, inorder, inBegin + offset + 1, inEnd);
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int len = preorder.size();
    return build(preorder, 0, len - 1, inorder, 0, len - 1);
  }
};

// Accepted
// 203/203 cases passed (44 ms)
// Your runtime beats 40.32 % of cpp submissions
// Your memory usage beats 79.05 % of cpp submissions (25.9 MB)
// @lc code=end

