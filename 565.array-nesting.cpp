/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */

// @lc code=start
auto speedup = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
public:
  int arrayNesting(vector<int>& nums) {
    int answer = 0;
    int len = nums.size();
    vector<bool> vis(len);
    for(int i = 0; i < len; ++i) {
      if(vis[i]) continue;
      int cur = i;
      int chain = 0;
      while(!vis[cur]) {
        chain += 1;
        vis[cur] = true;
        cur = nums[cur];
      }
      answer = max(answer, chain);
    }
    return answer;
  }
};

// Accepted
// 856/856 cases passed (12 ms)
// Your runtime beats 96.44 % of cpp submissions
// Your memory usage beats 37.89 % of cpp submissions (30.3 MB)
// @lc code=end

