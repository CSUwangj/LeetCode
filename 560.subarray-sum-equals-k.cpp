/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
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
  int subarraySum(vector<int>& nums, int k) {
    map<int, int> prefixCount{{0, 1}};
    int sum = 0;
    int answer = 0;
    for(auto n : nums) {
      sum += n;
      if(prefixCount.count(sum - k)) {
        answer += prefixCount[sum - k];
      }
      prefixCount[sum] += 1;
    }
    return answer;
  }
};

// Accepted
// 89/89 cases passed (96 ms)
// Your runtime beats 63.45 % of cpp submissions
// Your memory usage beats 39.62 % of cpp submissions (38.3 MB)
// @lc code=end
