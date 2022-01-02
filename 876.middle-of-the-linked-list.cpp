/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
class Solution {
  int length(ListNode *head) {
    int result = 0;
    while(head) {
      result += 1;
      head = head->next;
    }
    return result;
  }
  ListNode *advance(ListNode *head, int count) {
    while(count--) {
      head = head->next;
    }
    return head;
  }
public:
  ListNode* middleNode(ListNode* head) {
    return advance(head, length(head) / 2);
  }
};

// Accepted
// 36/36 cases passed (4 ms)
// Your runtime beats 40.59 % of cpp submissions
// Your memory usage beats 96.09 % of cpp submissions (7 MB)
// @lc code=end

