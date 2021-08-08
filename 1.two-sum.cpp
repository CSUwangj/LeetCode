/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
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
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> pos;
    int p = 0;
    for(auto i : nums) {
      if(pos.count(target - i)) {
        return {pos[target - i], p};
      }
      pos[i] = p++;
    }
    return {};
  }
};

// Accepted
// 54/54 cases passed (4 ms)
// Your runtime beats 99.68 % of cpp submissions
// Your memory usage beats 57.34 % of cpp submissions (10.6 MB)
// @lc code=end

