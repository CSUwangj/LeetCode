/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> count;
    for(auto n : arr) {
      count[n] += 1;
    }
    vector<int> c;
    c.reserve(count.size());
    for(const auto &[_, cnt] : count) {
      c.push_back(cnt);
    }
    sort(c.begin(), c.end());
    return (unique(c.begin(), c.end()) - c.begin()) == c.size();
  }
};

// Accepted
// 64/64 cases passed (8 ms)
// Your runtime beats 37.44 % of cpp submissions
// Your memory usage beats 6.37 % of cpp submissions (8.3 MB)
// @lc code=end

