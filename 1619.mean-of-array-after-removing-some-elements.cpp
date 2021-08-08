/*
 * @lc app=leetcode id=1619 lang=cpp
 *
 * [1619] Mean of Array After Removing Some Elements
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
  double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int sz = arr.size();
    double sum = 0;
    for(int i = sz / 20; i < sz - sz / 20; ++i) {
      sum += arr[i];
    }
    return sum / (sz - sz / 10);
  }
};

// Accepted
// 50/50 cases passed (8 ms)
// Your runtime beats 71.57 % of cpp submissions
// Your memory usage beats 13.07 % of cpp submissions (9.6 MB)
// @lc code=end

