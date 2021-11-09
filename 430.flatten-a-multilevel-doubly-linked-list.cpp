/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
class Solution {
  pair<Node*, Node*> _flatten(Node *head) {
    if(!head) return {nullptr, nullptr};
    Node *resultHead = head;
    Node *resultTail = nullptr;
    Node *cur = head;
    while (cur) {
      if (cur->child) {
        auto [h, t] = _flatten(cur->child);
        t->next = cur->next;
        if(cur->next) {
          cur->next->prev = t;
        }
        cur->next = h;
        h->prev = cur;
        cur->child = nullptr;
        cur = t;
      }
      resultTail = cur;
      cur = cur->next;
    }
    return {resultHead, resultTail};
  }
public:
  Node* flatten(Node* head) {
    return _flatten(head).first;
  }
};

// Accepted
// 26/26 cases passed (4 ms)
// Your runtime beats 75.52 % of cpp submissions
// Your memory usage beats 20.82 % of cpp submissions (7.5 MB)
// @lc code=end

