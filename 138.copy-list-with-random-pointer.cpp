/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
class Solution {
public:
  Node* copyRandomList(Node* head) {
    if(!head) return nullptr;
    // copy nodes
    Node *cur = head;
    while(cur) {
      Node *newNode = new Node(cur->val);
      newNode->next = cur->next;
      newNode->random = cur->random;
      cur->next = newNode;
      cur = newNode->next;
    }

    // fix random
    cur = head;
    while(cur) {
      cur = cur->next;
      if(cur->random) cur->random = cur->random->next;
      cur = cur->next;
    }
    
    // separate two list
    Node *newHead = head->next;
    cur = head;
    Node *newCur = newHead;
    while(cur) {
      cur->next = newCur->next;
      cur = cur->next;
      newCur->next = cur ? cur->next : nullptr;
      newCur = newCur->next;
    }
    
    return newHead;
  }
};

// Accepted
// 19/19 cases passed (8 ms)
// Your runtime beats 84.2 % of cpp submissions
// Your memory usage beats 98.36 % of cpp submissions (11.1 MB)
// @lc code=end
