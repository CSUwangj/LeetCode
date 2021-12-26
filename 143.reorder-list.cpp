/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    int result = 0;
    while(head) {
      result += 1;
      head = head->next;
    }
    return result;
  }
  ListNode *advance(ListNode *head, int count) {
    while(--count) {
      head = head->next;
    }
    return head;
  }
  ListNode *reverse(ListNode *head) {
    ListNode *tail = nullptr;
    while(head) {
      ListNode *tmp = head->next;
      head->next = tail;
      tail = head;
      head = tmp;
    }
    return tail;
  }
  void merge(ListNode *head1, ListNode *head2) {
    while(head1 && head2) {
      ListNode *tmp2 = head2->next;
      head2->next = head1->next;
      head1->next = head2;
      head1 = head2->next;
      head2 = tmp2;
    }
  }
public:
  void reorderList(ListNode* head) {
    int len = length(head);
    ListNode *tail1 = advance(head, (len + 1) / 2);
    ListNode *head2 = tail1->next;
    tail1->next = nullptr;
    head2 = reverse(head2);
    merge(head, head2);
  }
};

// Accepted
// 12/12 cases passed (32 ms)
// Your runtime beats 95.77 % of cpp submissions
// Your memory usage beats 76.71 % of cpp submissions (17.8 MB)
// @lc code=end
