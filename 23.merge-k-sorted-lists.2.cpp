/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct cmp {
  bool operator()(const ListNode *a, const ListNode *b) const {
    return a->val > b->val;
  }
};
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
    for(auto list : lists) {
      if(list) pq.push(list);
    }
    ListNode *newHead = new ListNode();
    ListNode *cur = newHead;
    while(pq.size()) {
      auto nxt = pq.top();
      pq.pop();
      if(nxt->next) {
        pq.push(nxt->next);
      }
      cur->next = nxt;
      cur = cur->next;
    }
    return newHead->next;
  }
};

// Accepted
// 133/133 cases passed (23 ms)
// Your runtime beats 78.38 % of cpp submissions
// Your memory usage beats 74.95 % of cpp submissions (13.3 MB)
// @lc code=end
