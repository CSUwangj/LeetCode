/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
class Solution {
  bool noDeletion(int *cnt) {
    int pos = 0;
    while(pos < 26 && !cnt[pos]) pos += 1;
    if(!pos) pos += 1;
    while(pos < 26 && cnt[pos] != cnt[pos - 1]) pos += 1;
    return pos == 26;
  }
public:
  int minDeletions(string s) {
    int cnt[26] = {};
    for(auto c : s) {
      cnt[c - 'a'] += 1;
    }
    sort(cnt, cnt + 26);
    if(noDeletion(cnt)) return 0;
    int pos = 0;
    while(pos < 26 && !cnt[pos]) pos += 1;
    int answer = 0;
    for(int i = pos + 1; i < 26; ++i) {
      if(cnt[i] != cnt[i - 1]) continue;
      for(int j = i - 1; j >= pos; --j) {
        if(!cnt[j] || cnt[j] != cnt[j + 1]) break;
        cnt[j] -= 1;
        answer += 1;
      }
    }
    return answer;
  }
};

// Accepted
// 103/103 cases passed (43 ms)
// Your runtime beats 92.49 % of cpp submissions
// Your memory usage beats 77.52 % of cpp submissions (17.2 MB)
// @lc code=end

