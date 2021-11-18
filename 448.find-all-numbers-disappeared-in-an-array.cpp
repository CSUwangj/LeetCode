/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
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
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for(auto i : nums) {
      i = i < 0 ? -i : i;
      nums[i - 1] = nums[i - 1] < 0 ? nums[i - 1] : -nums[i - 1];    
    }
    vector<int> answer;
    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] > 0) {
        answer.push_back(i + 1);
      }
    }
    return answer;
  }
};

// Accepted
// 33/33 cases passed (28 ms)
// Your runtime beats 99.89 % of cpp submissions
// Your memory usage beats 54.3 % of cpp submissions (33.8 MB)
// @lc code=end

