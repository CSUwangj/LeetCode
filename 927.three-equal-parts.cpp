/*
 * @lc app=leetcode id=927 lang=cpp
 *
 * [927] Three Equal Parts
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int ones[30000];
class Solution {
public:
  vector<int> threeEqualParts(vector<int>& arr) {
    int len = arr.size();
    int count = 0;
    for(int i = 0; i < len; ++i) {
      if(arr[len - i - 1]) {
        ones[count++] = i;
      }
    }
    if(count % 3) return {-1, -1};
    if(!count) return {0,2};
    int target = count / 3;
    int tailZero = ones[0];
    int headBegin = ones[target * 2] - tailZero;
    int midBegin = ones[target] - tailZero;
    if(ones[target - 1] >= midBegin || ones[target * 2 - 1] >= headBegin) return {-1, -1};
    int tailCur = 0;
    int midCur = midBegin;
    int headCur = headBegin;
    for(int i = 0; i < target; ++i) {
      if(ones[i] - tailCur != ones[target + i] - midCur || ones[target + i] - midCur != ones[target * 2 + i] - headCur) {
        return {-1, -1};
      }
      tailCur = ones[i];
      midCur = ones[target + i];
      headCur = ones[target * 2 + i];
    }
    return {len - headBegin - 1, len - midBegin};
  }
};

// Accepted
// 118/118 cases passed (20 ms) | not stable due to leetcode server...
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 43.37 % of cpp submissions (39 MB)
// @lc code=end

