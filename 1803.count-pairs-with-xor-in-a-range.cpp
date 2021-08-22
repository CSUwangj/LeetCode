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

int solveOne(TrieNode *cur, int num, int low, int high, int rest, bool mustLessThanHigh = false, bool mustGreaterThanLow = false) {
  // cout << num << ' ' << low <<  ' ' << high << ' ' << rest << ' ' << mustLessThanHigh << ' ' << mustGreaterThanLow <<endl;
  if(!cur) return 0;
  if(rest == -1) return cur->count;
  if(mustGreaterThanLow && mustLessThanHigh) return cur->count;
  int result = 0;
  bool ok[2] = { true, true };
  bool lowBit = low & (1 << rest);
  bool highBit = high & (1 << rest);
  bool numBit = (num & (1 << rest));
  // cout <<"## " << num << ' ' << low <<  ' ' << high << ' ' << rest << ' ' << mustLessThanHigh << ' ' << mustGreaterThanLow <<endl;
  if(!mustGreaterThanLow) {
    if(lowBit) {
      ok[numBit] = false;
    }
  }
  if(!mustLessThanHigh) {
    if(!highBit) {
      ok[!numBit] = false;
    }
  }
  for(int i = 0; i < 2; ++i) {
    if(!ok[i]) continue;
    if(i == numBit) {
      if(highBit) {
        result += solveOne(cur->child[i], num, low, high, rest - 1, true, mustGreaterThanLow);
      } else {
        result += solveOne(cur->child[i], num, low, high, rest - 1, mustLessThanHigh, mustGreaterThanLow);
      }
    } else {
      if(!lowBit) {
        result += solveOne(cur->child[i], num, low, high, rest - 1, mustLessThanHigh, true);
      } else {
        result += solveOne(cur->child[i], num, low, high, rest - 1, mustLessThanHigh, mustGreaterThanLow);
      }
    }
  }
  return result;
}

int solve(vector<int> &nums, int low, int high) {
  TrieNode *root = new TrieNode();
  int answer = 0;
  for(auto n : nums) {
    answer += solveOne(root, n, low, high, 14);
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
// 63/63 cases passed (280 ms)
// Your runtime beats 30.08 % of cpp submissions
// Your memory usage beats 36.72 % of cpp submissions (71.6 MB)
// @lc code=end

