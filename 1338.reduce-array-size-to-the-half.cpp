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
class Solution {
public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> cnt;
    for(auto i : arr) cnt[i] += 1;
    vector<int> amount;
    for(auto [_, c] : cnt) {
      cout << _ << ' '<< c << endl;
      amount.push_back(c);
    }
    sort(amount.begin(), amount.end(), greater<int>());
    for(int i = 1; i < amount.size(); ++i) {
      amount[i] += amount[i-1];
    }
    int target = (arr.size() + 1) / 2;
    return lower_bound(amount.begin(), amount.end(), target) - amount.begin() + 1;
  }
};

// Accepted
// 33/33 cases passed (574 ms)
// Your runtime beats 10.13 % of cpp submissions
// Your memory usage beats 48.79 % of cpp submissions (78.4 MB)
// @lc code=end

