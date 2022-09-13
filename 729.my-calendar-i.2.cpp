/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
  set<pair<int, int>> times;
public:
  MyCalendar(){}
  
  bool book(int start, int end) {
    auto it = times.upper_bound({start, end});
    if(it != times.end() && it->second < end) return false;
    times.insert({end, start});
    return true;
  }
};

// Accepted
// 107/107 cases passed (167 ms)
// Your runtime beats 51.09 % of cpp submissions
// Your memory usage beats 31.77 % of cpp submissions (38.9 MB)
// @lc code=end

