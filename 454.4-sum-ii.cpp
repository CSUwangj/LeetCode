/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
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
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    map<int, int> sum;
    for(auto n1 : nums1) {
      for(auto n2 : nums2) {
        sum[n1 + n2] += 1;
      }
    }
    int answer = 0;
    for(auto n3 : nums3) {
      for(auto n4 : nums4) {
        if(sum.count(-n3 - n4)) answer += sum[-n3 - n4];
      } 
    }
    return answer;
  }
};

// Accepted
// 132/132 cases passed (408 ms)
// Your runtime beats 27.73 % of cpp submissions
// Your memory usage beats 29.68 % of cpp submissions (24.7 MB)
// @lc code=end
