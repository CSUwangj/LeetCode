/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution {
public:
  bool checkIfPangram(string sentence) {
    set<char> st(sentence.begin(), sentence.end());
    return st.size() == 26;
  }
};

// Accepted
// 79/79 cases passed (3 ms)
// Your runtime beats 80.34 % of cpp submissions
// Your memory usage beats 31.31 % of cpp submissions (6.7 MB)
// @lc code=end

