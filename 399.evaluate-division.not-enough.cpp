/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> results;
    int len = equations.size();
    for(int i = 0; i < len; ++i) {
      results[equations[i][0]][equations[i][1]] = values[i];
    }
    for(const auto &[a, _] : results) {
      for(const auto &[s, v] : _) {
        cout << a << " / " << s << " = " << v << endl;
      }
    }
    vector<double> answer;
    answer.reserve(queries.size());
    for(const auto &query: queries) {
      if(results.count(query[0]) && results[0].count(query[1])) {
        answer.push_back(results[query[0]][query[1]]);
        continue;
      }
      if(!results.count(query[0]) || !results.count(query[1])) {
        answer.push_back(-1);
        continue;
      }
      bool found = false;
      for(const auto &[denominator, result] : results[query[0]]) {
        if(results[query[1]].count(denominator)) {
          found = true;
          answer.push_back(result / results[query[1]][denominator]);
          break;
        }
      }
      if(found) continue;
    }
    return answer;
  }
};
// @lc code=end
