/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *newHead = new ListNode();
    ListNode *cur = newHead;
    while(head) {
      if(head->val != val) {
        cur->next = head;
        cur = cur->next;
      }
      head = head->next;
    }
    cur->next = nullptr;
    return newHead->next;
  }
};

// Accepted
// 66/66 cases passed (20 ms)
// Your runtime beats 84.92 % of cpp submissions
// Your memory usage beats 79.14 % of cpp submissions (15 MB)
// @lc code=end

