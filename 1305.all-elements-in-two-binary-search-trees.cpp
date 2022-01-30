/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Stream {
  TreeNode *root;
  TreeNode *cur = root;
  int current;
public:
  Stream(TreeNode *r) : root(r) {
    iterate();
  }
  int getNum() {
    return current;
  }
  bool hasNum() {
    return current != INT_MAX;
  }
  void iterate() {
    if(!cur) {
      current = INT_MAX;
      return;
    }
    while(cur) {
      if(cur->left) {
        TreeNode *left = cur->left;
        while(left->right && left->right != cur) {
          left = left->right;
        }
        if(left->right == cur) {
          left->right = nullptr;
          current = cur->val;
          cur = cur->right;
          return;
        } else {
          left->right = cur;
          cur = cur->left;
        }
      } else {
        current = cur->val;
        cur = cur->right;
        return;
      }
    }
  }
};
class Solution {
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> answer;
    Stream stream1(root1);
    Stream stream2(root2);
    while(stream1.hasNum() && stream2.hasNum()) {
      if(stream1.getNum() <= stream2.getNum()) {
        answer.push_back(stream1.getNum());
        stream1.iterate();
      } else {
        answer.push_back(stream2.getNum());
        stream2.iterate();
      }
    }
    while(stream1.hasNum()) {
      answer.push_back(stream1.getNum());
      stream1.iterate();
    }
    while(stream2.hasNum()) {
      answer.push_back(stream2.getNum());
      stream2.iterate();
    }
    return answer;
  }
};

// Accepted
// 48/48 cases passed (211 ms)
// Your runtime beats 35.95 % of cpp submissions
// Your memory usage beats 67.43 % of cpp submissions (84.5 MB)
// @lc code=end
