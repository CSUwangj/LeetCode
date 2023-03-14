/*
 * @lc app=leetcode id=2306 lang=cpp
 *
 * [2306] Naming a Company
 */

// @lc code=start
class Solution {
public:
  long long distinctNames(vector<string>& ideas) {
    long long answer = 0;

    unordered_set<string> suffixes[26];
    for(const auto &idea : ideas) {
      suffixes[idea[0] - 'a'].insert(idea.substr(1));
    }

    for(int i = 0; i < 25; ++i) {
      for(int j = i + 1; j < 26; ++j) {
        int same = 0;
        for(const auto &suffix : suffixes[i]) {
          if(suffixes[j].count(suffix)) {
            same += 1;
          }
        }

        answer += 2 * (suffixes[i].size() - same) * (suffixes[j].size() - same);
      }
    }

    return answer;
  }
};

// Accepted
// 89/89 cases passed (458 ms)
// Your runtime beats 90.24 % of cpp submissions
// Your memory usage beats 43.9 % of cpp submissions (83.4 MB)
// @lc code=end

