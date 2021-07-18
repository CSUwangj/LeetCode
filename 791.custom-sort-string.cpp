/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
class Solution {
public:
  string customSortString(string order, string str) {
    int pos[128] = {};
    for(int i = 0; i < order.length(); ++i) pos[order[i]] = i + 1;
    sort(str.begin(), str.end(), [&](const char &a, const char &b) {
      return pos[a] < pos[b];
    });
    return str;
  }
};
// @lc code=end

