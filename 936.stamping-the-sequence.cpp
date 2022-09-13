/*
 * @lc app=leetcode id=936 lang=cpp
 *
 * [936] Stamping The Sequence
 */

// @lc code=start
class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    int sLen = stamp.length();
    int tLen = target.length();
    vector<int> answer;
    string helper(tLen, '?');
    bool found = false;
    do {
      found = false;
      for(int i = 0; i <= tLen - sLen; ++i) {
        bool add = false;
        int match = 0;
        for(int j = 0; j < sLen; ++j) {
          if(helper[i + j] != '?') {
            match += 1;
          } else if(stamp[j] == target[i + j]) {
            match += 1;
            add = true;
          }
        }
        if(add && match == sLen) {
          for(int j = 0; j < sLen; ++j) if(helper[i + j] == '?') helper[i + j] = stamp[j];
          answer.push_back(i);
          found = true;
        }
      }
    } while(found);
    if(find(helper.begin(), helper.end(), '?') != helper.end()) return {};
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 262/262 cases passed (14 ms)
// Your runtime beats 74.59 % of cpp submissions
// Your memory usage beats 76.23 % of cpp submissions (7.5 MB)
// @lc code=end

