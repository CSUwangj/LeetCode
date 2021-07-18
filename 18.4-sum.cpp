/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
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
    vector<int> &cur,
    vector<int> &nums,
    int index,
    int rest,
    int count
  ) {
    // cout << rest << " " << index << " " << count << endl;
    if(!count) {
      if(!rest) answer.push_back(cur);
      return;
    }
    if(nums.back() * count < rest) return;
    int prev = INT_MIN;
    while(index < len) {
      index = upper_bound(nums.begin() + index, nums.end(), prev) - nums.begin();
      if(index >= len) return;
      prev = nums[index];
      if(prev * count <= rest) {
        cur.push_back(prev);
        solve(answer, cur, nums, index + 1, rest - prev, count - 1);
        cur.pop_back();
      }
    }
  }
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> answer;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    len = nums.size();
    solve(answer, tmp, nums, 0, target, 4);
    return answer;
  }
};

// Accepted
// 283/283 cases passed (288 ms)
// Your runtime beats 6.98 % of cpp submissions
// Your memory usage beats 45.62 % of cpp submissions (13.1 MB)
// @lc code=end

