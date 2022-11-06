/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
  ListNode* deleteMiddle(ListNode* head) {
    ListNode *newHead = new ListNode(0, head);
    ListNode *fast = newHead;
    ListNode *slow = newHead;
    ListNode *cur = newHead;
    while(fast->next && fast->next->next) {
      fast = fast->next;
      if(fast->next) {
        fast = fast->next;
      }
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return newHead->next;
  }
};

// Accepted
// 70 / 70 cases passed (1043 ms)
// Your runtime beats 97.62 % of cpp submissions
// Your memory usage beats 20.46 % of cpp submissions (294.9 MB)
// @lc code=end
