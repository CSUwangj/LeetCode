/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> count;
    for(auto n : arr) {
      count[n] += 1;
    }
    unordered_set<int> st;
    for(const auto &[_, cnt] : count) {
      if(st.count(cnt)) return false;
      st.insert(cnt);
    }
    return true;
  }
};

// Accepted
// 64/64 cases passed (3 ms)
// Your runtime beats 86.2 % of cpp submissions
// Your memory usage beats 20.75 % of cpp submissions (8.3 MB)
// @lc code=end

