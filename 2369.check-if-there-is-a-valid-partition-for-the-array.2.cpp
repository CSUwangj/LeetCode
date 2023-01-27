/*
 * @lc app=leetcode id=2369 lang=cpp
 *
 * [2369] Check if There is a Valid Partition For The Array
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<int> result;
  int check(int pos, const vector<int> &nums) {
    if(pos >= nums.size()) return result[pos] = 1;
    if(result[pos] != -1) return result[pos];
    if(pos + 1 < nums.size() && nums[pos] == nums[pos + 1]) {
      if(check(pos + 2, nums)) return result[pos] = 1;
    }
    if(pos + 2 < nums.size() && ((nums[pos] == nums[pos + 1] && nums[pos] == nums[pos + 2]) ||
                                 (nums[pos] + 1 == nums[pos + 1] && nums[pos] + 2 == nums[pos + 2]))) {
      if(check(pos + 3, nums)) return result[pos] = 1;
    }
    return result[pos] = 0;
  }
public:
  bool validPartition(vector<int>& nums) {
    result.resize(nums.size() + 1, -1);
    return check(0, nums) == 1;
  }
};

// Accepted
// 117/117 cases passed (169 ms)
// Your runtime beats 96.64 % of cpp submissions
// Your memory usage beats 34.87 % of cpp submissions (92.3 MB)
// @lc code=end

