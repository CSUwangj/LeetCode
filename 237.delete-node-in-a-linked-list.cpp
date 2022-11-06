/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  void deleteNode(ListNode* node) {
    while(node->next && node->next->next) {
      node->val = node->next->val;
      node = node->next;
    }
    node->val = node->next->val;
    node->next = nullptr;
  }
};

// Accepted
// 41/41 cases passed (4 ms)
// Your runtime beats 99.95 % of cpp submissions
// Your memory usage beats 73.12 % of cpp submissions (7.5 MB)
// @lc code=end

