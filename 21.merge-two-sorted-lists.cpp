/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode *newHead = new ListNode(0);
    ListNode *cur = newHead;
    while(a && b) {
      if(a->val < b->val) {
        cur->next = a;
        a = a->next;
      } else {
        cur->next = b;
        b = b->next;
      }
      cur = cur->next;
    }
    if(a) cur->next = a;
    else cur->next = b;
    return newHead->next;
  }
};

// Accepted
// 208/208 cases passed (11 ms)
// Your runtime beats 55.46 % of cpp submissions
// Your memory usage beats 15.87 % of cpp submissions (15 MB)
// @lc code=end
