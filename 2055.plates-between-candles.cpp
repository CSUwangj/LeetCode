/*
 * @lc app=leetcode id=2055 lang=cpp
 *
 * [2055] Plates Between Candles
 */

// @lc code=start
class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int len = s.length();
    int prefix[len];
    int left[len];
    int right[len];
    prefix[0] = s[0] == '*';
    int rightMost = 0;
    left[0] = rightMost;
    for(int i = 1; i < len; ++i) {
      prefix[i] = prefix[i - 1];
      if(s[i] == '*') {
        prefix[i] += 1;
      } else {
        rightMost = i;
      }
      left[i] = rightMost;
    }
    int leftMost = len - 1;
    right[len - 1] = leftMost;
    for(int i = len - 2; i >= 0; --i) {
      if(s[i] == '|') {
        leftMost = i;
      }
      right[i] = leftMost;
    }
    vector<int> answer;
    answer.reserve(queries.size());
    for(const auto &query : queries) {
      int result = prefix[left[query[1]]] - prefix[right[query[0]]];
      if(result < 0) {
        result = 0;
      }
      answer.push_back(result);
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (811 ms)
// Your runtime beats 24.73 % of cpp submissions
// Your memory usage beats 95.3 % of cpp submissions (137.8 MB)
// @lc code=end
