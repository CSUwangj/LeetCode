/*
 * @lc app=leetcode id=1859 lang=cpp
 *
 * [1859] Sorting the Sentence
 */

// @lc code=start
class Solution {
public:
  string sortSentence(string s) {
    vector<string> container(9);
    string word;
    int len = 0;
    for(auto c : s) {
      if(isdigit(c)) {
        container[c - '1'] = word;
        len = max(c - '0', len);
        word = "";
      } else if(isalpha(c)) {
        word.push_back(c);
      }
    }
    string answer = container[0];
    for(int i = 1; i < len; ++i) {
      answer = answer + " " + container[i];
    }
    return answer;
  }
};

// Accepted
// 45/45 cases passed (3 ms)
// Your runtime beats 9.94 % of cpp submissions
// Your memory usage beats 40.63 % of cpp submissions (6.4 MB)
// @lc code=end

