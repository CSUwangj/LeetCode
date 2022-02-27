/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *newHead = new ListNode(-1, head);
    ListNode *cur = newHead;
    while(head) {
      if(head->next) {
        ListNode *tmp = head->next->next;
        cur->next = head->next;
        head->next->next = head;
        head->next = tmp;
        cur = cur->next->next;
        head = tmp;
      } else {
        head = head->next;
      }
    }
    return newHead->next;
  }
};

// Accepted
// 55/55 cases passed (3 ms)
// Your runtime beats 70.43 % of cpp submissions
// Your memory usage beats 55.41 % of cpp submissions (7.5 MB)
// @lc code=end
