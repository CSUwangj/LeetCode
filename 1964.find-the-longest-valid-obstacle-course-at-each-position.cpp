/*
 * @lc app=leetcode id=1964 lang=cpp
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
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
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    int len = obstacles.size();

    vector<int> LIS;
    vector<int> answer;
    answer.reserve(len);

    for(auto i : obstacles) {
      int pos = lower_bound(LIS.begin(), LIS.end(), i + 1) - LIS.begin();
      if(pos == LIS.size()) {
        LIS.push_back(i);
      } else {
        LIS[pos] = i;
      }
      answer.push_back(pos + 1);
    }

    return answer;
  }
};

// Accepted
// 78/78 cases passed (297 ms)
// Your runtime beats 77.08 % of cpp submissions
// Your memory usage beats 59.03 % of cpp submissions (117.9 MB)
// @lc code=end

