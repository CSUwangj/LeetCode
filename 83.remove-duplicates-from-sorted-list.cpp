/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode *newHead = new ListNode(-101);
    ListNode *cur = newHead;
    while(head) {
      if(cur->val != head->val) {
        cur->next = head;
        cur = head;
      }
      head = head->next;
    }
    cur->next = nullptr;
    return newHead->next;
  }
};

// Accepted
// 166/166 cases passed (8 ms)
// Your runtime beats 91.84 % of cpp submissions
// Your memory usage beats 36.29 % of cpp submissions (11.7 MB)
// @lc code=end
