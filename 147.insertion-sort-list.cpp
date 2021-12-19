/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
  ListNode* insertionSortList(ListNode* head) {
    ListNode *newHead = new ListNode();
    ListNode *cur = head;
    while(cur) {
      ListNode *newCur = newHead;
      ListNode *newPrev = nullptr;
      while(newCur->next && newCur->next->val < cur->val) {
        newCur = newCur->next;
      }
      ListNode *tmp = cur->next;
      cur->next = newCur ->next;
      newCur->next = cur;
      cur = tmp;
    }
    return newHead->next;
  }
};

// Accepted
// 19/19 cases passed (47 ms)
// Your runtime beats 44.67 % of cpp submissions
// Your memory usage beats 14.7 % of cpp submissions (9.8 MB)
// @lc code=end
