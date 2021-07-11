/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[1001];
class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    // cout << "$$$$$$$$$$$$"<<endl;
    int len1 = nums1.size();
    int len2 = nums2.size();
    int answer = 0;
    memset(dp, 0, sizeof(dp[0]) * (len1 + 1));
    for(int i = len1 - 1; i >= 0; --i) {
      for(int j = 0; j < len2; ++j) {
        if(nums1[i] == nums2[j]) {
          dp[j] = dp[j + 1] + 1;
          answer = max(answer, dp[j]);
        } else {
          dp[j] = 0;
        }
        // cout << dp[j] <<  ' ';
      }
      // cout << endl;
    }
    return answer;
  }
};
// @lc code=end

