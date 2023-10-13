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
public:
  bool validPartition(vector<int>& nums) {
    int len = nums.size();
    vector<bool> valid(len + 1);
    valid[0] = true;
    if(nums[0] == nums[1]) valid[2] = true;

    for(int i = 3; i <= len; ++i) {
      if(valid[i - 2] && nums[i - 2] == nums[i - 1]) {
        valid[i] = true;
      }
      if(valid[i - 3] && ((nums[i - 3] == nums[i - 2] && nums[i - 3] == nums[i - 1]) ||
                          (nums[i - 3] + 1 == nums[i - 2] && nums[i - 2] + 1 == nums[i - 1]))) {
        valid[i] = true;
      }
    }

    return valid.back();
  }
};

// Accepted
// 117/117 cases passed (65 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 92.92 % of cpp submissions (83.9 MB)
// @lc code=end

