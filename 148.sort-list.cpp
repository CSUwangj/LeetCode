/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int length(ListNode* head){
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
public:
  ListNode* sortList(ListNode* head) {
    int interval = 1, len = length(head);
    if(len < 2) return head;
    ListNode *new_head = new ListNode(-1, head);
    while(interval < len) {
      ListNode *pre = new_head, *h = pre->next;
      while(h) {
        ListNode *h1 = h;
        int cnt = interval;
        while(h && cnt) {
          h = h->next;
          cnt -= 1;
        }
        if(cnt) break;
        ListNode *h2 = h;
        cnt = interval;
        while(h && cnt) {
          h = h->next;
          cnt -= 1;
        }
        int len1 = interval, len2 = interval - cnt;
        while(len1 && len2) {
          if(h1->val < h2->val) {
            pre->next = h1;
            h1 = h1->next;
            len1 -= 1;
          } else {
            pre->next = h2;
            h2 = h2->next;
            len2 -= 1;
          }
          pre = pre->next;
        }
        pre->next = len1 ? h1 : h2;
        while(len1 > 0 || len2 > 0) {
          pre = pre->next;
          len1 -= 1;
          len2 -= 1;
        }
        pre->next = h;
      }
      interval *= 2;
    }
    return new_head->next;
  }
};

// Accepted
// 28/28 cases passed (76 ms)
// Your runtime beats 99.22 % of cpp submissions
// Your memory usage beats 97.96 % of cpp submissions (28.9 MB)
// @lc code=end
