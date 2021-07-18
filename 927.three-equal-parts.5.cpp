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
    if(count % 3) return {-1, -1};
    if(!count) return {0,2};
    int target = count / 3;
    int mid = -1;
    int head = -1;
    int tail = -1;
    int cur = 0;
    int i;
    for(i = 0; i < len && head == -1; ++i) {
      cur += arr[i];
      if(cur) head = i;
    }
    for(; i < len && mid == -1; ++i) {
      cur += arr[i];
      if(cur == target + 1) mid = i;
    }
    for(; i < len && tail == -1; ++i) {
      cur += arr[i];
      if(cur == target * 2 + 1) tail = i;
    }
    while(tail < len && arr[head] == arr[mid] && arr[mid] == arr[tail]) {
      head += 1;
      mid += 1;
      tail += 1;
    }
    if(tail == len) return {head - 1, mid};
    return {-1, -1};
  }
};

// Accepted
// 118/118 cases passed (16 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 81.33 % of cpp submissions (38.9 MB)
// @lc code=end

