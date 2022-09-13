/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
  set<int> times;
public:
  MyCalendar(){}
  
  bool book(int start, int end) {
    bool isStart = true;
    bool removeEnd = false;
    bool removeStart = false;
    int prevStart = -1;
    for(auto i : times) {
      if(isStart && i == end) removeEnd = true;
      if(!isStart && i == start) removeStart = true;
      if(isStart) {
        prevStart = i;
      } else {
        if(start >= prevStart && start < i) return false;
        if(end <= i && end > prevStart) return false;
      }
      isStart = !isStart;
    }
    if(times.upper_bound(start) != times.lower_bound(end)) return false;
    if(removeEnd) times.erase(end);
    else times.insert(end);
    if(removeStart) times.erase(start);
    else times.insert(start);
    return true;
  }
};

// Accepted
// 107/107 cases passed (596 ms)
// Your runtime beats 5.03 % of cpp submissions
// Your memory usage beats 12.23 % of cpp submissions (40.7 MB)
// @lc code=end

