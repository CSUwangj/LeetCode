/*
 * @lc app=leetcode id=1601 lang=cpp
 *
 * [1601] Maximum Number of Achievable Transfer Requests
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<int> record;
  int ans;
  bool sat() {
    for(auto i : record) {
      if(i) return false;
    }
    return true;
  }
  void dfs(int index, int cur, vector<vector<int>>& requests){
    if(index == requests.size()) {
      if(sat() && cur > ans) ans = cur;
      return;
    }
    dfs(index+1, cur, requests);
    record[requests[index][0]] -= 1;
    record[requests[index][1]] += 1;
    dfs(index+1, cur+1, requests);
    record[requests[index][0]] += 1;
    record[requests[index][1]] -= 1;
  }
public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    record = vector<int>(n+1);
    dfs(0, 0, requests);
    return ans;
  }
};

// Accepted
// 117/117 cases passed (98 ms)
// Your runtime beats 80.39 % of cpp submissions
// Your memory usage beats 75.49 % of cpp submissions (8.8 MB)
// @lc code=end

