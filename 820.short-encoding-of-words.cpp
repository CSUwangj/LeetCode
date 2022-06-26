/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */

// @lc code=start
class Solution {
public:
  int minimumLengthEncoding(vector<string>& words) {
    for(auto &word : words) reverse(word.begin(), word.end());
    sort(words.begin(), words.end());
    int answer = 0;
    int len = words.size();
    for(int i = 0; i < len; ++i) {
      bool unique = true;
      if(i < len - 1 && words[i + 1].rfind(words[i], 0) == 0) unique = false;
      if(unique) answer += words[i].length() + 1;
    }
    return answer;
  }
};

// Accepted
// 36/36 cases passed (50 ms)
// Your runtime beats 93.14 % of cpp submissions
// Your memory usage beats 94.12 % of cpp submissions (13.8 MB)
// @lc code=end

