/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 */

// @lc code=start
class Solution {
public:
  string smallestSubsequence(string s) {
    vector<int> cnt(26);
    vector<int> used(26);
    for(auto c : s) {
      cnt[c - 'a'] += 1;
    }

    string answer;
    for(auto c : s) {
      if(used[c - 'a']) {
        cnt[c - 'a'] -= 1;
        continue;
      }
      while(answer.length() && answer.back() > c && cnt[answer.back() - 'a']) {
        used[answer.back() - 'a'] = false;
        answer.pop_back();
      }
      answer.push_back(c);
      used[c - 'a'] = true;
      cnt[c - 'a'] -= 1;
    }
    return answer;
  }
};

// Accepted
// 68/68 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 64.3 % of cpp submissions (6.3 MB)
// @lc code=end
