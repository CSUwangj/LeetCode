/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 */

// @lc code=start
class Solution {
public:
  int getDecimalValue(ListNode* head) {
    int ans = 0;
    while(head) {
      ans <<= 1;
      ans |= head->val;
      head = head->next;
    }
    return ans;
  }
};

// Accepted
// 102/102 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.93 % of cpp submissions (8.1 MB)
// @lc code=end
