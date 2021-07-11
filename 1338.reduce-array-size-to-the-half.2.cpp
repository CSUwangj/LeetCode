/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
auto speedup = []() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int cnt[100001];
class Solution {
public:
  int minSetSize(vector<int>& arr) {
    memset(cnt, 0, sizeof(cnt));
    int maxNum = *max_element(arr.begin(), arr.end());
    for(auto i : arr) cnt[i] += 1;
    int target = arr.size() / 2;
    sort(cnt, cnt + maxNum + 1, greater<int>());
    if(cnt[0] == 1) return target;
    if(cnt[0] > target) return 1;
    int len = 1;
    for(int i = 1; cnt[i]; ++i) {
      cnt[i] += cnt[i - 1];
      len = i; 
    }
    return lower_bound(cnt, cnt + len, target) - cnt + 1;
  }
};
// @lc code=end

