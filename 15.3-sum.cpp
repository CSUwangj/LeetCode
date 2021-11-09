/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
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
  
  vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
    vector<vector<int>> answer;
    unordered_set<int> st;
    for(int i = start; i < len; ++i) {
      if(answer.size() && answer.back()[1] == nums[i]) continue;
      if(st.count(nums[i])) {
        answer.push_back(vector<int>{target-nums[i], nums[i]});
      }
      st.insert(target-nums[i]);
    }
    return answer;
  }
  
  vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k) {
    vector<vector<int>> answer;
    if(nums[start] * k > target || target > nums.back() * k) return answer;
    if(k == 2) return twoSum(nums, target, start);
    for(int i = start; i <= len-k; ++i) {
      if(i != start && nums[i] == nums[i-1]) continue;
      for(auto &vec : kSum(nums, target-nums[i], i+1, k-1)) {
        answer.push_back({nums[i]});
        answer.back().insert(answer.back().end(), vec.begin(), vec.end());
      }
    }
    return answer;
  }
  
  void init(vector<int> &nums) {
    len = nums.size();
    sort(nums.begin(), nums.end());
  }
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if(nums.size() < 3) return vector<vector<int>>();
    init(nums);
    return kSum(nums, 0, 0, 3);
  }
};

// Accepted
// 318/318 cases passed (1080 ms)
// Your runtime beats 11.23 % of cpp submissions
// Your memory usage beats 5.06 % of cpp submissions (275.3 MB)
// @lc code=end

