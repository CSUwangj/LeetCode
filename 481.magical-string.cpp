/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 */

// @lc code=start
class Solution {
public:
  int magicalString(int n) {
    if(n < 4) return 1;
    vector<bool> result(n);
    result[0] = true;
    int pos = 2;
    int end = 3;
    bool isTwo = false;
    while(end < n) {
      if(isTwo) {
        end += 2 - result[pos];
      } else {
        result[end++] = true;
        if(end < n && !result[pos]) result[end++] = true;
      }
      isTwo = !isTwo;
      pos += 1;
    }
    // for(auto i : result) { cout << i;}
    return accumulate(result.begin(), result.end(), 0);
  }
};

// Accepted
// 64/64 cases passed (4 ms)
// Your runtime beats 92.22 % of cpp submissions
// Your memory usage beats 82.78 % of cpp submissions (6.5 MB)
// @lc code=end

