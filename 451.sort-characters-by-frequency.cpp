/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int count[128] = {};
public:
  string frequencySort(string s) {
    for(auto c : s) {
      count[c] += 1;
    }
    sort(s.begin(), s.end(), [&](char a, char b) {
      return count[a] > count[b] || (count[a] == count[b] && a > b);
    });
    return s;
  }
};

// Accepted
// 33/33 cases passed (61 ms)
// Your runtime beats 8.74 % of cpp submissions
// Your memory usage beats 95.21 % of cpp submissions (8 MB)
// @lc code=end

