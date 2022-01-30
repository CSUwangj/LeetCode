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
      cur->children[bit] = new TrieNode;
    }
    cur = cur->children[bit];
  }
}

int getResult(TrieNode *root, int num) {
  TrieNode *cur = root;
  int result = 0;
  for(int i = 30; i >= 0; --i) {
    result <<= 1;
    int bit = ((num >> i) & 1);
    if(!cur->children[!bit]) {
      cur = cur->children[bit];
    } else {
      result |= 1;
      cur = cur->children[!bit];
    }
  }
  return result;
}
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    TrieNode *root = new TrieNode();
    for(auto num : nums) {
      insert(root, num);
    }
    int answer = 0;
    set<int> st;
    for(auto num : nums) {
      if(st.count(num)) continue;
      st.insert(num);
      answer = max(answer, getResult(root, num));
    }
    return answer;
  }
};

// Accepted
// 41/41 cases passed (305 ms)
// Your runtime beats 65.16 % of cpp submissions
// Your memory usage beats 53.89 % of cpp submissions (71.3 MB)
// @lc code=end
