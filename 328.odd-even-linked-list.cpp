/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
  ListNode* oddEvenList(ListNode* head) {
    ListNode *oddHead = new ListNode();
    ListNode *evenHead = new ListNode();
    ListNode *oddCur = oddHead;
    ListNode *evenCur = evenHead;
    while(head) {
      oddCur->next = head;
      oddCur = oddCur->next;
      head = head->next;
      evenCur->next = head;
      evenCur = evenCur->next;
      if(head) head = head->next;
    }
    oddCur->next = evenHead->next;
    return oddHead->next;
  }
};

// Accepted
// 70/70 cases passed (8 ms)
// Your runtime beats 92.49 % of cpp submissions
// Your memory usage beats 29.12 % of cpp submissions (10.6 MB)
// @lc code=end
