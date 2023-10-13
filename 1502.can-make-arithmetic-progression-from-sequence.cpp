/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

// @lc code=start
class Solution {
public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    for(int i = 2; i < arr.size(); ++i) {
      if(arr[i] - arr[i - 1] != diff) return false;
    }
    return true;
  }
};

// Accepted
// 109/109 cases passed (9 ms)
// Your runtime beats 22.98 % of cpp submissions
// Your memory usage beats 28.46 % of cpp submissions (9.1 MB)
// @lc code=end

