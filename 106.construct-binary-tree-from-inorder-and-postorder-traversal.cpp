/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  TreeNode* buildTree(
    vector<int> &inorder, 
    int inBegin,
    int inEnd,
    vector<int> &postorder,
    int postBegin,
    int postEnd
  ) {
    if(inBegin > inEnd) return nullptr;
    TreeNode *root = new TreeNode(postorder[postEnd]);
    for(int i = inBegin; i <= inEnd; ++i) {
      if(inorder[i] == postorder[postEnd]) {
        int offset = i - inBegin;
        root->left = buildTree(inorder, inBegin, inBegin + offset - 1, postorder, postBegin, postBegin + offset - 1);
        root->right = buildTree(inorder, inBegin + offset + 1, inEnd, postorder, postBegin + offset, postEnd - 1);
        break;
      }
    }
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int len = inorder.size();
    return buildTree(inorder, 0, len - 1, postorder, 0, len - 1);
  }
};

// Accepted
// 202/202 cases passed (32 ms)
// Your runtime beats 32.56 % of cpp submissions
// Your memory usage beats 62.12 % of cpp submissions (26.2 MB)
// @lc code=end
