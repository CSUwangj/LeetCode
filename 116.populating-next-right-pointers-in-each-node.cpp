/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
class Solution {
public:
  Node* connect(Node* root) {
    Node *curLevel = root;
    while(curLevel) {
      Node *nextLevel = curLevel->left;
      Node *cur = curLevel;
      while(cur) {
        if(!cur->left) break;
        cur->left->next = cur->right;
        if(cur->next) {
          cur->right->next = cur->next->left;
        }
        cur = cur->next;
      }
      curLevel = nextLevel;
    }
    return root;
  }
};

// Accepted
// 58/58 cases passed (20 ms)
// Your runtime beats 57.99 % of cpp submissions
// Your memory usage beats 65.94 % of cpp submissions (16.8 MB)
// @lc code=end
