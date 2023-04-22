/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
class Solution {
  ListNode *cur;
  
  int length(ListNode *head) {
    int len = 0;
    while(head) {
      len += 1;
      head = head->next;
    }
    return len;
  }
  
  TreeNode *buildBST(int begin, int end) {
    if(begin > end) return nullptr;
    
    int mid = (begin + end) >> 1;
    TreeNode *left = buildBST(begin, mid - 1);
    
    TreeNode *root = new TreeNode(cur->val);
    root->left = left;
    
    cur = cur->next;
    root->right = buildBST(mid + 1, end);
    
    return root;
  }
  
public:
  TreeNode* sortedListToBST(ListNode* head) {
    int len = length(head);
    cur = head;
    return buildBST(0, len-1);
  }
};

// Accepted
// 32/32 cases passed (24 ms)
// Your runtime beats 84.58 % of cpp submissions
// Your memory usage beats 71.93 % of cpp submissions (28.4 MB)
// @lc code=end

