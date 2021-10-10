/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
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
  vector<int> findDuplicates(vector<int>& nums) {
    int len = nums.size();
    vector<int> answer;
    for(int i = 0; i < len; ++i) {
      int pos = nums[i] > 0 ? nums[i] - 1 : -1 - nums[i];
      cout << pos << endl;
      if(nums[pos] > 0) {
        nums[pos] = -nums[pos]; 
      } else {
        answer.push_back(pos + 1);
      }
    }
    return answer;
  }
};

// Accepted
// 28/28 cases passed (60 ms)
// Your runtime beats 53.68 % of cpp submissions
// Your memory usage beats 74.16 % of cpp submissions (33.5 MB)
// @lc code=end

