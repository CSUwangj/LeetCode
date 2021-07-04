/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return vector<vector<int>>();
    sort(intervals.begin(), intervals.end());
    int len = intervals.size();
    
    vector<vector<int>> answer;
    vector<int> current = intervals[0];
    for(int i = 1; i < len; ++i) {
      if(intervals[i][0] > current[1]) {
        answer.push_back(current);
        current = intervals[i];
      } else {
        current[1] = max(current[1], intervals[i][1]);
      }
    }
    answer.push_back(current);
    return answer;
  }
};
// @lc code=end

