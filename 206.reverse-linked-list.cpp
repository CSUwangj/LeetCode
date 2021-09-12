/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
class Solution {
public:
  ListNode* reverseList(ListNode* head, ListNode* tail = nullptr) {
    if(!head) return tail;
    ListNode *next = head->next;
    head->next = tail;
    return reverseList(next, head);
  }
};

// Accepted
// 28/28 cases passed (4 ms)
// Your runtime beats 96.22 % of cpp submissions
// Your memory usage beats 97.51 % of cpp submissions (8.2 MB)
// @lc code=end

