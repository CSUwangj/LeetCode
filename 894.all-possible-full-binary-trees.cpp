/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
  vector<vector<TreeNode*>> FBTs;
  void generateFBTs(int N) {
    FBTs.resize(N+1);
    FBTs[1].push_back(new TreeNode(0));
    for(int i = 3; i <= N; i += 2) {
      for(int j = 1; j < i; j += 2) {
        for(auto left : FBTs[j]) {
          for(auto right: FBTs[i-j-1]) {
            FBTs[i].push_back(new TreeNode(0, deepcopy(left), deepcopy(right)));
          }
        }
      }
    }
  }
  
  TreeNode* deepcopy(TreeNode *root) {
    if(!root) return nullptr;
    return new TreeNode(0, deepcopy(root->left), deepcopy(root->right));
  }
  
public:
  vector<TreeNode*> allPossibleFBT(int N) {
    if(N % 2 == 0) return vector<TreeNode*>();
    generateFBTs(N);
    return FBTs[N];
  }
};

// Accepted
// 20/20 cases passed (131 ms)
// Your runtime beats 19.55 % of cpp submissions
// Your memory usage beats 19.62 % of cpp submissions (37.5 MB)
// @lc code=end

