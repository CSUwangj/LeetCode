/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  int length(ListNode *head) {
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
  ListNode *getNNode(ListNode *&head, int n) {
    if(!head || !n) return nullptr;
    ListNode *newHead = head;
    while(--n && head) {
      head = head->next;
    }
    if(head) {
      ListNode *newCur = head->next;
      head->next = nullptr;
      head = newCur;
    }
    return newHead;
  }
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = length(head);
    int lenOfPart = len / k;
    vector<ListNode*> answer;
    while(k) {
      int partLen = lenOfPart + (lenOfPart * k < len);
      answer.push_back(getNNode(head, partLen));
      len -= partLen;
      k -= 1;
    }
    return answer;
  }
};

// Accepted
// 43/43 cases passed (4 ms)
// Your runtime beats 96.39 % of cpp submissions
// Your memory usage beats 91.57 % of cpp submissions (8.8 MB)
// @lc code=end

