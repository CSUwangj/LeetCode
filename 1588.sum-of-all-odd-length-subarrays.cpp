/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
 */

// @lc code=start
class Solution {
public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int len = arr.size();
    int answer = 0;
    for(int i = 0; i * 2 < len; ++i) {
      for(int j = 1; j <= len; j += 2) {
        int count = min(i + 1, j);
        count = min(count, len - j + 1);
        answer += count * arr[i];
        // cout << i << ' ' << j << ' ' << count << endl;
        if(i * 2 + 1 != len) answer += count * arr[len - i - 1];
      }
    }
    return answer;
  }
};

// Accepted
// 96/96 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 39.98 % of cpp submissions (8.4 MB)
// @lc code=end

