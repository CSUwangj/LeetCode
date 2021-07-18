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
class Solution {
public:
  vector<int> threeEqualParts(vector<int>& arr) {
    int len = arr.size();
    int count = accumulate(arr.begin(), arr.end(), 0);
    reverse(arr.begin(), arr.end());
    if(count % 3) return {-1, -1};
    if(!count) return {0,2};
    int target = count / 3;
    int tailZero = -1;
    int midBegin = -1;
    int headBegin = -1;
    int midEnd = -1;
    int tailEnd = -1;
    int cur = 0;
    for(int i = 0; i < len; ++i) {
      cur += arr[i];
      if(tailZero == -1 && arr[i]) tailZero = i;
      if(tailEnd == -1 && cur == target) tailEnd = i;
      if(midBegin == -1 && cur == target + 1) midBegin = i - tailZero;
      if(midEnd == -1 && cur == target * 2) midEnd = i;
      if(headBegin == -1 && cur == target * 2 + 1) {
        headBegin = i - tailZero;
        break;
      }
    }
    // cout << midBegin << " " << headBegin << " " << endl;
    if(midBegin <= tailEnd || headBegin <= midEnd) return {-1, -1};
    int tailCur = 0;
    int midCur = midBegin;
    int headCur = headBegin;
    while(tailCur < midBegin && midCur < headBegin && headCur < len) {
      if(arr[tailCur] != arr[midCur] || arr[midCur] != arr[headCur]) return {-1, -1};
      tailCur += 1;
      midCur += 1;
      headCur += 1;
    }
    return {len - headBegin - 1, len - midBegin};
  }
};

// Accepted
// 118/118 cases passed (28 ms)
// Your runtime beats 98.19 % of cpp submissions
// Your memory usage beats 81.33 % of cpp submissions (38.8 MB)
// @lc code=end

