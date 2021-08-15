/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool valid(map<int, int> cnt) {
    for(auto [i, c] : cnt) {
      if(!c) continue;
      if(!cnt.count(i * 2) || cnt[2 * i] < c) return false;
      cnt[i * 2] -= c;
    }
    return true;
  }
public:
  bool canReorderDoubled(vector<int>& arr) {
    map<int, int> cnt;
    for(auto i : arr) {
      if(i >= 0) cnt[i] += 1;
    }
    if((cnt[0]&1) || !valid(cnt)) return false;
    cnt.clear();
    for(auto i : arr) {
      if(i < 0) cnt[0 - i] += 1;
    }
    return valid(cnt);
  }
};

// Accepted
// 102/102 cases passed (48 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 16.93 % of cpp submissions (58.9 MB)
// @lc code=end

