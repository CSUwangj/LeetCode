/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
class Solution {
public:
  int longestSubsequence(vector<int>& arr, int difference) {
    map<int, int> existSubsequence;
    int answer = 0;
    for(auto i : arr) {
      existSubsequence[i] = max(existSubsequence[i], existSubsequence[i - difference] + 1);
      answer = max(answer, existSubsequence[i]);
    }

    return answer;
  }
};

// Accepted
// 39/39 cases passed (359 ms)
// Your runtime beats 5.03 % of cpp submissions
// Your memory usage beats 10.76 % of cpp submissions (57.6 MB)
// @lc code=end

