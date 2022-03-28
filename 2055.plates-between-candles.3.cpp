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
int lleft[100000];
int rright[100000];
class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int len = s.length();
    prefix[0] = s[0] == '*';
    int rightMost = 0;
    lleft[0] = rightMost;
    for(int i = 1; i < len; ++i) {
      prefix[i] = prefix[i - 1];
      if(s[i] == '*') {
        prefix[i] += 1;
      } else {
        rightMost = i;
      }
      lleft[i] = rightMost;
    }
    int leftMost = len - 1;
    rright[len - 1] = leftMost;
    for(int i = len - 2; i >= 0; --i) {
      if(s[i] == '|') {
        leftMost = i;
      }
      rright[i] = leftMost;
    }
    vector<int> answer;
    answer.reserve(queries.size());
    for(const auto &query : queries) {
      int result = prefix[lleft[query[1]]] - prefix[rright[query[0]]];
      if(result < 0) {
        result = 0;
      }
      answer.push_back(result);
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (407 ms)
// Your runtime beats 92.82 % of cpp submissions
// Your memory usage beats 95.72 % of cpp submissions (137.7 MB)
// @lc code=end
