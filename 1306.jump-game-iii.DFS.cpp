/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
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
  bool canReach(vector<int>& arr, int start) {
    int len = arr.size();
    vector<bool> vis(arr.size());
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(q.size()) {
      int cur = q.front();
      q.pop();
      if(!arr[cur]) return true;
      if(cur + arr[cur] < len && !vis[cur + arr[cur]]) {
        q.push(cur + arr[cur]);
        vis[cur + arr[cur]] = true;
      }
      if(cur - arr[cur] >= 0 && !vis[cur - arr[cur]]) {
        q.push(cur - arr[cur]);
        vis[cur - arr[cur]] = true;
      }
    }
    return false;
  }
};

// Accepted
// 56/56 cases passed (24 ms)
// Your runtime beats 99.69 % of cpp submissions
// Your memory usage beats 83.03 % of cpp submissions (31.3 MB)
// @lc code=end
