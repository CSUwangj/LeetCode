/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> answer;
    vector<int> cur = intervals.front();
    for(auto &interval : intervals) {
      if(interval[0] > cur[1]) {
        answer.push_back(cur);
        cur[0] = interval[0];
      }
      cur[1] = max(interval[1], cur[1]);
    }
    answer.emplace_back(cur);
    return answer;
  }
};

// Accepted
// 168/168 cases passed (16 ms)
// Your runtime beats 88.84 % of cpp submissions
// Your memory usage beats 94.91 % of cpp submissions (14.1 MB)
// @lc code=end

