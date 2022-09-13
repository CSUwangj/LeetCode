/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
class Solution {
  vector<string> m{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> answer;
    for(auto &word : words) {
      string code = "";
      for(auto c : word) {
        code += m[c-'a'];
      }
      answer.insert(code);
    }
    return answer.size();
  }
};

// Accepted
// 82/82 cases passed (4 ms)
// Your runtime beats 71.25 % of cpp submissions
// Your memory usage beats 61.19 % of cpp submissions (8.5 MB)
// @lc code=end

