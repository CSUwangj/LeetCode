/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
class Solution {
public:
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<int> count(26);
    for(auto &b : B) {
      vector<int> tmpCount(26);
      for(auto c : b) tmpCount[c - 'a'] += 1;
      for(int i = 0; i < 26; ++i) count[i] = max(count[i], tmpCount[i]);
    }
    
    vector<string> answer;
    for(auto &a : A) {
      vector<int> tmpCount(26);
      for(auto c : a) tmpCount[c - 'a'] += 1;
      bool universal = true;
      for(int i = 0; i < 26; ++i) universal &= tmpCount[i] >= count[i];
      if(universal) answer.push_back(a);
    }
    return answer;
  }
};

// Accepted
// 56/56 cases passed (282 ms)
// Your runtime beats 62.47 % of cpp submissions
// Your memory usage beats 65.17 % of cpp submissions (102.4 MB)
// @lc code=end

