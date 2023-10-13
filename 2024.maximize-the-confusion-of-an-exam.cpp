/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start
class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int answer = 0;
    int start = 0;
    int T = 0;
    for(int i = 0; i < answerKey.length(); ++i) {
      T += (answerKey[i] == 'T');
      while(T > k && i - start + 1 - T > k) {
        T -= (answerKey[start] == 'T');
        start += 1;
      }
      answer = max(answer, i - start + 1);
    }
    return answer;
  }
};

// Accepted
// 93/93 cases passed (18 ms)
// Your runtime beats 98.15 % of cpp submissions
// Your memory usage beats 59.24 % of cpp submissions (10 MB)
// @lc code=end

