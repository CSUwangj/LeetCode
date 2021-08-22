/*
 * @lc app=leetcode id=1803 lang=cpp
 *
 * [1803] Count Pairs With XOR in a Range
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  int count = 0;
  TrieNode *child[2] = {};
};

void insert(TrieNode *root, int num) {
  TrieNode *cur = root;
  root->count += 1;
  for(int i = 14; i >= 0; --i) {
    int index = !!(num & (1 << i));
    if(!cur->child[index]) {
      cur->child[index] = new TrieNode();
    }
    cur = cur->child[index];
    cur->count += 1;
  }
}
int find(TrieNode *root, int num, int target) {
  TrieNode *cur = root;
  int result = 0;
  for(int i = 14; i >= 0; --i) {
    // cout << "#" << num << ' ' << target << ' ' << i << ' ' << result << endl;
    if(!cur) break;
    bool numBit = num & (1 << i);
    bool targetBit = target & (1 << i);
    if(targetBit) {
      if(cur->child[numBit]) result += cur->child[numBit]->count;
      cur = cur->child[!numBit];
    } else {
      cur = cur->child[numBit];
    }
  }
  if(cur) result += cur->count;
  return result;
}
int solve(vector<int> &nums, int low, int high) {
  TrieNode *root = new TrieNode();
  int answer = 0;
  for(auto n : nums) {
    answer += find(root, n, high) - find(root, n, low - 1);
    // cout << find(root, n, high) << ' ' << find(root, n, low - 1) << ' ' << answer << endl;
    insert(root, n);
  }
  return answer;
}
class Solution {
public:
  int countPairs(vector<int>& nums, int low, int high) {
    return solve(nums, low, high);
  }
};

// Accepted
// 63/63 cases passed (164 ms)
// Your runtime beats 98.05 % of cpp submissions
// Your memory usage beats 36.72 % of cpp submissions (71.6 MB)
// @lc code=end

