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
  int length(ListNode *head) {
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
public:
  ListNode* deleteMiddle(ListNode* head) {
    int len = length(head);
    int toRemove = len / 2;
    ListNode *newHead = new ListNode(0, head);
    ListNode *cur = newHead;
    while(toRemove) {
      cur = cur->next;
      toRemove -= 1;
    }
    cur->next = cur->next->next;
    return newHead->next;
  }
};

// Accepted
// 70 / 70 cases passed (1346 ms)
// Your runtime beats 80.30 % of cpp submissions
// Your memory usage beats 20.46 % of cpp submissions (294.8 MB)
// @lc code=end
