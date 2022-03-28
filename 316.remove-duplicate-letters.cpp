/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
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
  string removeDuplicateLetters(string s) {
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
// 289/289 cases passed (4 ms)
// Your runtime beats 61.69 % of cpp submissions
// Your memory usage beats 66.29 % of cpp submissions (6.6 MB)
// @lc code=end
