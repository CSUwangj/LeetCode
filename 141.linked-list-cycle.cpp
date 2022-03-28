/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while(slow && fast) {
      if(!fast || !fast->next) return false;
      fast = fast->next->next;
      slow = slow->next;
      if(slow == fast) return true;
    }
    return false;
  }
};

// Accepted
// 21/21 cases passed (17 ms)
// Your runtime beats 42.1 % of cpp submissions
// Your memory usage beats 81.34 % of cpp submissions (7.9 MB)
// @lc code=end
