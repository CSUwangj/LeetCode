/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct Job {
  int start;
  int end;
  int profit;
  Job() {}
  Job(int start, int end, int profit): start(start), end(end), profit(profit) {}
  bool operator<(const Job& other) const { 
    return this->start < other.start;
  }
};
class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<Job> jobs;
    int len = startTime.size();
    for(int i = 0; i < startTime.size(); i++) {
      jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
    }
    sort(jobs.begin(), jobs.end());
    vector<int> dp(len);
    for(int i = 0; i < len; ++i) {
      dp[i] = jobs[i].profit;
    }
    for(int i = 0; i < len; i++) {
      if(i) {
        dp[i] = max(dp[i], dp[i - 1] - jobs[i - 1].profit + jobs[i].profit);
      }
      int pos = lower_bound(jobs.begin() + i, jobs.end(), jobs[i].end, 
        [](const Job& j, int endTime) {
          return j.start < endTime;
        }) - jobs.begin();
      if(pos < len && dp[pos] < dp[i] + jobs[pos].profit) dp[pos] = dp[i] + jobs[pos].profit;
    }
    return *max_element(dp.begin(), dp.end());
  }
};

// Accepted
// 30/30 cases passed (83 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.93 % of cpp submissions (50 MB)
// @lc code=end

