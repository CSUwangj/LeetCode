/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start
constexpr int pop_count(int x) {
  const int m1  = 0X55555555;
  const int m2  = 0X33333333;
  const int m4  = 0X0F0F0F0F;
  const int m8  = 0X00FF00FF;
  const int m16 = 0X0000FFFF;
  x = (x &  m1) + ((x >>  1) &  m1);
  x = (x &  m2) + ((x >>  2) &  m2);
  x = (x &  m4) + ((x >>  4) &  m4);
  x = (x &  m8) + ((x >>  8) &  m8);
  x = (x & m16) + ((x >> 16) & m16);
  return x;
}
class Solution {
  vector<int> getSubsequence(int mask, const vector<int> &array) {
    vector<int> result;
    for(int i = 0; i < array.size(); ++i) {
      if((1 << i) & mask) {
        result.push_back(array[i]);
      }
    }
    return result;
  }
  bool validSubsequence(int mask, const vector<int> &array) {
    int last = -101;
    for(int i = 0; i < array.size(); ++i) {
      if(!((1 << i) & mask)) continue;
      if(array[i] < last) return false;
      last = array[i];
    }
    return true;
  }
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    int bits = nums.size();
    int maxMask = 1 << bits;

    vector<vector<int>> answer;
    for(int i = 1; i < maxMask; ++i) {
      if(pop_count(i) < 2) continue;
      if(!validSubsequence(i, nums)) continue;
      answer.emplace_back(getSubsequence(i, nums));
    }

    sort(answer.begin(), answer.end());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    return answer;
  }
};

// Accepted
// 58/58 cases passed (162 ms)
// Your runtime beats 24.96 % of cpp submissions
// Your memory usage beats 33.17 % of cpp submissions (31.1 MB)
// @lc code=end

