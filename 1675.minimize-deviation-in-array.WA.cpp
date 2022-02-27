/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

// @lc code=start
// initialize a array with size 1e9 will be fucked up
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr int SZ = 100001;
int cnt[SZ];
class Solution {
public:
  int minimumDeviation(vector<int>& nums) {
    memset(cnt, 0, sizeof(cnt));
    int mmin = INT_MAX;
    int mmax = INT_MIN;
    for(auto i : nums) {
      if(i % 2 && i * 2 < SZ) i *= 2;
      mmin = min(mmin, i);
      mmax = max(mmax, i);
      cnt[i] += 1;
    }
    
    int answer = mmax - mmin;
    for(int i = mmax; i >= mmin; --i) {
      if(!cnt[i]) continue;
      answer = min(answer, i - mmin);
      if(i & 1) break;
      cnt[i / 2] += 1;
      if(i / 2 < mmin) mmin = i / 2;
    }
    return answer;
  }
};

// Accepted
// 76/76 cases passed (503 ms)
// Your runtime beats 26.49 % of cpp submissions
// Your memory usage beats 9.93 % of cpp submissions (122.2 MB)
// @lc code=end
