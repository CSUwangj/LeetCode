/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int len;
  void dfs(
    vector<vector<int>> &answer,
    vector<int> &cur,
    vector<int> &nums,
    int pos
  ) {
    if(pos == len) {
      answer.emplace_back(cur);
      return;
    }
    dfs(answer, cur, nums, pos + 1);
    cur.push_back(nums[pos]);
    dfs(answer, cur, nums, pos + 1);
    cur.pop_back();
  }
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    len = nums.size();
    vector<vector<int>> answer;
    vector<int> tmp;
    dfs(answer, tmp, nums, 0);
    return answer;
  }
};

// Accepted
// 10/10 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 33.03 % of cpp submissions (10.8 MB)
// @lc code=end
