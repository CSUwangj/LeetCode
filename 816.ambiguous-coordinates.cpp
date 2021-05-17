/*
 * @lc app=leetcode id=816 lang=cpp
 *
 * [816] Ambiguous Coordinates
 */

// @lc code=start
class Solution {
  vector<string> getCoordinate(string num) {
    if(num.length() > 1 && num.front() == '0' && num.back() == '0') return {};
    if(num.back() == '0') return {num};
    if(num.front() == '0') return {"0." + num.substr(1)};
    vector<string> result{num};
    for(int i = 1; i < num.length(); ++i) {
      result.push_back(num.substr(0, i) + "." + num.substr(i));
    }
    return result;
  }
public:
  vector<string> ambiguousCoordinates(string s) {
    int len = s.length();
    vector<string> answer;
    for(int i = 1; i < s.length() - 2; ++i) {
      for(auto first : getCoordinate(s.substr(1, i))) {
        for(auto second : getCoordinate(s.substr(1 + i, len - 2 - i))) {
          answer.push_back("(" + first + ", " + second + ")");
        }
      }
    }
    return answer;
  }
};
// @lc code=end

