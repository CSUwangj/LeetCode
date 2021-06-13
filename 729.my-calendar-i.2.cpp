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

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

