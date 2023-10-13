/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
  bool buddyStrings(string A, string B) {
    if(A.size() != B.size())return false;
    vector<int> cnt(128);
    int pos = -1;
    for(int i = 0; i < A.size(); ++i) {
      cnt[A[i]] ++;
      if(A[i] != B[i] && pos == -1) {
        pos = i;
      } else if (A[i] != B[i]) {
        char temp = A[i];
        A[i] = A[pos];
        A[pos] = temp;
        return A == B;
      }
    }
    return pos == -1 && *max_element(cnt.begin(), cnt.end()) > 1;
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 52.51 % of cpp submissions (7 MB)
// @lc code=end

