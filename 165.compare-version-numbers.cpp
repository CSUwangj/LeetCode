/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
  vector<int> parseVersion(const string &version) {
    vector<int> result;
    int current = 0;
    for(auto c : version) {
      if(isdigit(c)) {
        current *= 10;
        current += c - '0';
      } else {
        result.push_back(current);
        current = 0;
      }
    }
    result.push_back(current);
    return result;
  }
public:
  int compareVersion(string version1, string version2) {
    auto v1 = parseVersion(version1);
    auto v2 = parseVersion(version2);
    while(v1.size() != v2.size()) {
      if(v1.size() < v2.size()) {
        v1.push_back(0);
      } else {
        v2.push_back(0);
      }
    }
    if(v1 < v2) return -1;
    if(v1 == v2) return 0;
    return 1;
  }
};

// Accepted
// 81/81 cases passed (5 ms)
// Your runtime beats 15.77 % of cpp submissions
// Your memory usage beats 19.06 % of cpp submissions (6.3 MB)
// @lc code=end
