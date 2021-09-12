/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *newHead = nullptr;
    ListNode *prev;
    ListNode *cur = head;
    while(cur) {
      prev = cur;
      cur = cur->next;
      prev->next = newHead;
      newHead = prev;
    }
    return newHead;
  }
};

// Accepted
// 28/28 cases passed (4 ms)
// Your runtime beats 96.22 % of cpp submissions
// Your memory usage beats 97.51 % of cpp submissions (8.2 MB)
// @lc code=end

