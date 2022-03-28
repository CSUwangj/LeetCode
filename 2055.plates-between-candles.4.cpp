/*
 * @lc app=leetcode id=2055 lang=cpp
 *
 * [2055] Plates Between Candles
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int prefix[100000];
class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int len = s.length();
    set<int> pos;
    if(s[0] == '|') {
      pos.insert(0);
      prefix[0] = 0;
    } else {
      prefix[0] = 1;
    }
    for(int i = 1; i < len; ++i) {
      prefix[i] = prefix[i - 1];
      if(s[i] == '*') {
        prefix[i] += 1;
      } else {
        pos.insert(i);
      }
    }
    if(prefix[len - 1] == len) {
      return vector<int>(queries.size());
    }
    vector<int> answer;
    answer.reserve(queries.size());
    for(const auto &query : queries) {
      auto rit = pos.upper_bound(query[1]);
      if(rit == pos.begin()) {
        answer.push_back(0);
        continue;
      }
      int right = *--rit;
      int left = *pos.lower_bound(query[0]);
      int result = prefix[right] - prefix[left];
      if(result < 0) {
        result = 0;
      }
      answer.push_back(result);
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (352 ms)
// Your runtime beats 99.86 % of cpp submissions
// Your memory usage beats 57.32 % of cpp submissions (143.1 MB)
// @lc code=end
