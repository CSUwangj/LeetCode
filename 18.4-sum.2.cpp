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
  vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
    vector<vector<int>> answer;
    int end = len - 1;
    // cout << target << ' ' << start << ' ' << end << ' ';
    while(start < end) {
      int result = nums[start] + nums[end];
      if(result == target) {
        answer.push_back({nums[end], nums[start]});
        do { start += 1; } while(start < end && nums[start] == nums[start - 1]);
        do { end -= 1; } while(start < end && nums[end] == nums[end + 1]);
      } else if(result < target) {
        do { start += 1; } while(start < end && nums[start] == nums[start - 1]);
      } else {
        do { end -= 1; } while(start < end && nums[end] == nums[end + 1]);
      }
    } 
    // cout << answer << endl;
    return answer;
  }
  vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k) {
    vector<vector<int>> answer;
    // cout << target << ' ' << start << ' ' << k << endl;
    if(nums[start] * k > target || nums.back() * k < target) return answer;
    if(k == 2) return twoSum(nums, target, start);
    for(int i = start; i <= len - k; ++i) {
      if(i != start && nums[i] == nums[i - 1]) continue;
      for(auto &res : kSum(nums, target - nums[i], i + 1, k - 1)) {
        res.push_back(nums[i]);
        answer.emplace_back(move(res));
      }
    }
    return answer;
  }
  void init(vector<int> &nums) {
    len = nums.size();
    sort(nums.begin(), nums.end());
  }
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    init(nums);
    // cout << nums << endl;
    auto answer = kSum(nums, target, 0, 4);
    for(auto &res : answer) { 
      reverse(res.begin(), res.end());
    }
    return answer;
  }
};

// Accepted
// 283/283 cases passed (15 ms)
// Your runtime beats 91.73 % of cpp submissions
// Your memory usage beats 45.57 % of cpp submissions (13.1 MB)
// @lc code=end

