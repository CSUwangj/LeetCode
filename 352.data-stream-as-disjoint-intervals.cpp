/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
class SummaryRanges {
  vector<vector<int>> m;
public:
  void addNum(int val) {
    auto it = lower_bound(m.begin(), m.end(), vector<int>{val, val});
    int new_begin = val, new_end = val;
    if(it != m.begin() && ((*(--it))[1]+1 < val)) ++it;
    while(it != m.end() && val+1 >= (*it)[0] && val-1 <= (*it)[1]) {
      new_begin = min(new_begin, (*it)[0]);
      new_end = max(new_end, (*it)[1]);
      it = m.erase(it);
    }
    m.insert(it, vector<int> {new_begin, new_end});
  }
  
  vector<vector<int>> getIntervals() {
    vector<vector<int>> ans;
    for(auto &interval: m) {
      ans.push_back(interval);
    }
    return ans;
  }
};

// Accepted
// 9/9 cases passed (56 ms)
// Your runtime beats 92.94 % of cpp submissions
// Your memory usage beats 18.43 % of cpp submissions (34.3 MB)
// @lc code=end

