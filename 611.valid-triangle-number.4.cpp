/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    int count[1001] = {};
    int prefix[1001] = {};
    int mmax = -1;
    for(auto i : nums) {
      count[i] += 1;
      if(i > mmax) mmax = i;
    }
    for(int i = 1; i < 1001; ++i) {
      prefix[i] = prefix[i-1] + count[i];
    }

    int answer = 0;
    for(int i = mmax; i >= 1 ; --i) {
      if(!count[i] || prefix[i] < 3) continue;
      // cout << i << " ";
      if(count[i] > 2) answer += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
      // cout << answer << ' ';
      for(int j = i - 1; j; --j) {
        if(!count[j] ) continue;
        if(count[j] > 1 && j * 2 > i) {
          answer += count[i] * count[j] * (count[j] - 1) / 2;
        }
        if(count[i] > 1 && i * 2 > j) {
          answer += count[j] * count[i] * (count[i] - 1) / 2;
        }
        if(j - 1 > i - j) {
          answer += (prefix[j - 1] - prefix[i - j]) * count[i] * count[j];
        }
      }
      // cout  << answer << endl;
    }
    return answer;
  }
};

// Accepted
// 233/233 cases passed (12 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 19.41 % of cpp submissions (12.8 MB)
// @lc code=end

