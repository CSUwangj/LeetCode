/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
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
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int len = arr.size();
    int minDiff = INT_MAX;
    for(int i = 1; i < len; ++i) {
      minDiff = min(minDiff, arr[i] - arr[i - 1]);
    }

    vector<vector<int>> answer;
    for(int i = 1; i < len; ++i) {
      if(arr[i] - arr[i - 1] == minDiff) {
        answer.push_back({arr[i - 1], arr[i]});
      }
    }

    return answer;
  }
};

// Accepted
// 36/36 cases passed (36 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 76.65 % of cpp submissions (32.2 MB)
// @lc code=end
