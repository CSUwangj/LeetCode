#include <bits/stdc++.h>
#define LL long long
#define mk(a, b) make_pair(a, b)
#define ULL unsigned long long
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x) & (-x))
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *head) {
  while (head) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << endl;
}

class Solution {
  default_random_engine generator;
  int length(ListNode *head) {
    if (!head) return 0;
    int len = 0;
    if (head->val == -1000000) head = head->next;
    while (head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
  ListNode *advance(ListNode *head, int cnt) {
    if (head->val == -1000000) head = head->next;
    while (cnt--) head = head->next;
    return head;
  }

 public:
  ListNode *sortList(ListNode *head) {
    int len = length(head);
    if (len < 2) {
      if (head && head->val == -1000000) head = head->next;
      return head;
    }
    ListNode *new_head_less = new ListNode(-1000000), *new_head_more = new ListNode(-1000000);
    ListNode *new_cur_less = new_head_less, *new_cur_more = new_head_more;
    uniform_int_distribution<int> distribution(1, len - 1);
    int pivot_offset = distribution(generator);
    ListNode *mid_pri = advance(head, pivot_offset - 1);
    ListNode *mid = mid_pri->next;
    ListNode *mid_cur = mid;
    mid_pri->next = mid->next;
    mid->next = nullptr;
    if (head->val == -1000000) head = head->next;
    while (head) {
      ListNode *nxt = head->next;
      if (head->val < mid->val) {
        new_cur_less->next = head;
        new_cur_less = new_cur_less->next;
        new_cur_less->next = nullptr;
      } else if (head->val > mid->val) {
        new_cur_more->next = head;
        new_cur_more = new_cur_more->next;
        new_cur_more->next = nullptr;
      } else {
        mid_cur->next = head;
        mid_cur = mid_cur->next;
        mid_cur->next = nullptr;
      }
      head = nxt;
    }
    new_head_less->next = sortList(new_head_less);
    new_cur_less = new_head_less;
    while (new_cur_less->next) new_cur_less = new_cur_less->next;
    new_head_more->next = sortList(new_head_more);
    new_cur_less->next = mid;
    mid_cur->next = new_head_more->next;
    return new_head_less->next;
  }
};

int main() {
  ListNode *head = new ListNode(4);
  ListNode *cur = head;
  cur->next = new ListNode(1);
  cur = cur->next;
  cur->next = new ListNode(2);
  cur = cur->next;
  cur->next = new ListNode(3);
  cur = cur->next;
  print(head);
  auto a = Solution();
  ListNode *new_head = a.sortList(head);
  print(new_head);
  return 0;
}