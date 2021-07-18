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
    vector<int> ones;
    for(int i = 0; i < len; ++i) {
      if(arr[i]) {
        ones.push_back(i);
      }
    }
    int count = ones.size();
    if(count % 3) return {-1, -1};
    if(!count) return {0, 2};
    int target = count / 3;
    int head = ones[0];
    int mid = ones[target];
    int tail = ones[target * 2];
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
// 118/118 cases passed (8 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 16.27 % of cpp submissions (40.5 MB)
// @lc code=end

