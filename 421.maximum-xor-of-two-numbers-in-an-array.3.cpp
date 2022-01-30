/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  TrieNode *children[2] = {};
};

void insert(TrieNode *root, int num) {
  TrieNode *cur = root;
  for(int i = 30; i >= 0; --i) {
    int bit = ((num >> i) & 1);
    if(!cur->children[bit]) {
      cur->children[bit] = new TrieNode();
    }
    cur = cur->children[bit];
  }
}

int getResult(TrieNode *cur1, TrieNode *cur2, int pos) {
  if(pos < 0 || !cur1 || !cur2) return 0;
  int result = 0;
  int result2 = 0;
  if(cur1->children[0] && cur2->children[1]) result = (1 << pos) + getResult(cur1->children[0], cur2->children[1], pos - 1);
  if(cur2->children[0] && cur1->children[1]) result = max(result, (1 << pos) + getResult(cur2->children[0], cur1->children[1], pos - 1));
  if(result) return result;
  if(cur1->children[0]) return getResult(cur1->children[0], cur2->children[0], pos - 1);
  return getResult(cur1->children[1], cur2->children[1], pos - 1);
}
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    TrieNode *root = new TrieNode();
    for(auto num : nums) {
      insert(root, num);
    }
    int answer = 0;
    int pos = 30;
    TrieNode *cur = root;
    while(pos >= 0) {
      if(!cur->children[0]) {
        cur = cur->children[1];
      } else if(!cur->children[1]) {
        cur = cur->children[0];
      } else {
        return (1 << pos) | getResult(cur->children[0], cur->children[1], pos - 1);
      }
      pos -= 1;
    }
    return answer;
  }
};

// Accepted
// 41/41 cases passed (295 ms)
// Your runtime beats 66.42 % of cpp submissions
// Your memory usage beats 95.74 % of cpp submissions (64.3 MB)
// @lc code=end
