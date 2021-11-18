/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class CombinationIterator {
  bool _hasNext = true;
  string _next;
  string chars;
  string permutation;
  int len;
  int combLen;
public:
  CombinationIterator(string characters, int combinationLength) : chars(characters), combLen(combinationLength) {
    len = chars.length();
    _next = chars.substr(0, combLen);
    for(int i = 0; i < combLen; ++i) {
      permutation.push_back(i);
    }
  }

  string next() {
    string result = _next;
    if(_next.front() == chars[len - combLen]) {
      _hasNext = false;
    } else {
      int pos;
      for(pos = combLen - 1; pos >= 0 && permutation[pos] == pos + len - combLen; --pos) {}
      permutation[pos] += 1;
      _next[pos] = chars[permutation[pos]];
      for(int i = pos + 1; i < combLen; ++i) {
        permutation[i] = permutation[i - 1] + 1;
        _next[i] = chars[permutation[i]];
      }
    }
    return result;
  }

  bool hasNext() {
    return _hasNext;
  }
};

// Accepted
// 16/16 cases passed (8 ms)
// Your runtime beats 95.09 % of cpp submissions
// Your memory usage beats 87.95 % of cpp submissions (12.1 MB)
// @lc code=end

