/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
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
  int maxTurbulenceSize(vector<int>& arr) {
    int len = arr.size();
    if(len == 1) return 1;
    int count = 1 + (arr[0] != arr[1]);
    int answer = count;
    for(int i = 1; i < len - 1; ++i) {
      if((arr[i + 1] > arr[i] && arr[i] < arr[i - 1]) ||
         (arr[i + 1] < arr[i] && arr[i] > arr[i - 1])) {
        count += 1;
      } else {
        count = 1 + (arr[i] != arr[i + 1]);
      }
      answer = max(answer, count);
    }

    return answer;
  }
};

// Accepted
// 89/89 cases passed (32 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.59 % of cpp submissions (40.1 MB)
// @lc code=end

