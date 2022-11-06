/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
  vector<pair<int, int>> p = {
    {1000, 100},
    {500, 100},
    {100, 10},
    {50, 10},
    {10, 1},
    {5, 1},
    {1, 0}
  };
  unordered_map<int, char> mp = {
    {1000, 'M'},
    {500, 'D'},
    {100, 'C'},
    {50, 'L'},
    {10, 'X'},
    {5, 'V'},
    {1, 'I'}
  };
public:
  string intToRoman(int num) {
    string answer;
    for(auto [larger, less] : p) {
      while(num >= larger) {
        num -= larger;
        answer.push_back(mp[larger]);
      }
      if(num >= larger - less) {
        num -= larger - less;
        answer.push_back(mp[less]);
        answer.push_back(mp[larger]);
      }
    }
    return answer;
  }
};

// Accepted
// 3999/3999 cases passed (11 ms)
// Your runtime beats 72.59 % of cpp submissions
// Your memory usage beats 31.42 % of cpp submissions (8.2 MB)
// @lc code=end

