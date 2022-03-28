/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *newHead = new ListNode();
    ListNode *newCur = newHead;
    while(head) {
      if(head->next && head->val == head->next->val) {
        int val = head->val;
        while(head && head->val == val) head = head->next;
        continue;
      }
      newCur->next = head;
      newCur = newCur->next;
      head = head->next;
    }
    newCur->next = nullptr;
    return newHead->next;
  }
};

// Accepted
// 166/166 cases passed (19 ms)
// Your runtime beats 16.25 % of cpp submissions
// Your memory usage beats 20.51 % of cpp submissions (11.2 MB)
// @lc code=end
