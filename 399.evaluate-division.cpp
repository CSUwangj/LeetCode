/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> fractions;
    queue<pair<string, string>> q;
    int len = equations.size();
    for(int i = 0; i < len; ++i) {
      if(equations[i][0] == equations[i][1]) continue;
      fractions[equations[i][0]][equations[i][1]] = values[i];
      fractions[equations[i][1]][equations[i][0]] = 1.0 / values[i];
      fractions[equations[i][0]][equations[i][0]] = 1.0;
      fractions[equations[i][1]][equations[i][1]] = 1.0;
      // (a / b) * (b / c) = a / c
      // (a / b) / (c / b) = a / c
      // add both fraction itself and its reciprocal so
      // we don't need to concern about so much case
      q.push({equations[i][0], equations[i][1]});
      q.push({equations[i][1], equations[i][0]});
    }
    while(q.size()) {
      const auto [numerator1, denominator1] = q.front();
      q.pop();
      // numerator2 == denominator1
      for(const auto &[denominator2, value] : fractions[denominator1]) {
        if(fractions[numerator1].count(denominator2)) continue;
        fractions[numerator1][denominator2] = value * fractions[numerator1][denominator1];
        q.push({numerator1, denominator2});
      }
    }
    vector<double> answer;
    answer.reserve(queries.size());
    for(const auto &query : queries) {
      if(fractions.count(query[0]) && fractions[query[0]].count(query[1])) {
        answer.push_back(fractions[query[0]][query[1]]);
      } else {
        answer.push_back(-1);
      }
    }
    return answer;
  }
};

// Accepted
// 24/24 cases passed (4 ms)
// Your runtime beats 51.34 % of cpp submissions
// Your memory usage beats 18.38 % of cpp submissions (8.6 MB)
// @lc code=end
