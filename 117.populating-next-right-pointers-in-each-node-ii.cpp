/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
class Solution {
public:
  Node* connect(Node* root) {
    Node *parent = root;
    Node *cur;
    Node *first;
    while(parent) {
      first = NULL;
      while(parent && !(parent->left || parent->right)) parent = parent->next;
      if(!parent) break;
      if(parent->left) {
        cur = parent->left;
        first = cur;
        if(parent->right) {
          cur->next = parent->right;
          cur = cur->next;
        }
      } else {
        cur = parent->right;
        first = cur;
      }
      parent = parent->next;
      while(cur) {
        while(parent && !(parent->left || parent->right)) parent = parent->next;
        if(!parent) break;
        if(parent->left) {
          cur->next = parent->left;
          if(parent->right) {
            cur = cur->next;
            cur->next = parent->right;
          }
        } else {
          cur->next = parent->right;
        }
        parent = parent->next;
        cur = cur->next;
      }
      parent = first;
    }
    return root;
  }
};

// Accepted
// 55/55 cases passed (18 ms)
// Your runtime beats 54.04 % of cpp submissions
// Your memory usage beats 94.51 % of cpp submissions (17.2 MB)
// @lc code=end

