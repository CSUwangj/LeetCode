/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *newHead = new ListNode();
    ListNode *cur = newHead;
    int carry = 0;
    while(l1 && l2) {
      int val = l1->val + l2->val + carry;
      carry = val / 10;
      cur->next = new ListNode(val%10);
      cur = cur->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    ListNode *rest = l1 ? l1 : l2;
    while(rest) {
      int val = rest->val + carry;
      carry = val / 10;
      cur->next = new ListNode(val%10);
      cur = cur->next;
      rest = rest->next;
    }
    if(carry) cur->next = new ListNode(carry);
    return newHead->next;
  }
};

// Accepted
// 1568/1568 cases passed (40 ms)
// Your runtime beats 71.08 % of cpp submissions
// Your memory usage beats 11.57 % of cpp submissions (71.6 MB)
// @lc code=end
