/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
class Solution {
  int length(ListNode* head) {
    ListNode *cur = head;
    int len = 0;
    while(cur) {
        cur = cur->next;
        len += 1;
    }
    return len;
  }
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if(!k) return head;
    int len = length(head);
    if(!len || k % len == 0) return head;
    k = len - (k % len);
    ListNode *cur = head, *previous;
    while(k--) {
      previous = cur;
      cur = cur->next;
    }
    ListNode *new_head = cur;
    while(cur->next) cur = cur->next;
    cur->next = head;
    previous->next = NULL;
    return new_head;
  }
};

// Accepted
// 231/231 cases passed (8 ms)
// Your runtime beats 73.85 % of cpp submissions
// Your memory usage beats 88.88 % of cpp submissions (11.7 MB)
// @lc code=end
