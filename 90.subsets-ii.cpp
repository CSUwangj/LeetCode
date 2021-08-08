/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
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
  void solve(
    vector<vector<int>> &answer,
    vector<int> &container,
    vector<int>& nums,
    int begin
  ) {
    if(begin == len) {
      answer.push_back(container);
      return;
    }
    int end = begin + 1;
    while(end < len && nums[end] == nums[end - 1]) end += 1;
    solve(answer, container, nums, end);
    for(int i = begin; i < end; ++i) {
      container.push_back(nums[begin]);
      solve(answer, container, nums, end);
    }
    for(int i = begin; i < end; ++i) {
      container.pop_back();
    }
  }
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    len = nums.size();
    vector<vector<int>> answer;
    vector<int> tmp;
    solve(answer, tmp, nums, 0);
    return answer;
  }
};

// Accepted
// 19/19 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 24.23 % of cpp submissions (11.6 MB)
// @lc code=end

