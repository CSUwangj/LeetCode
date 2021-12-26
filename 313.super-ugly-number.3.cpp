/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  using ll = long long;
  using plli = pair<ll, int>;
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int len = primes.size();
    vector<int> indice(len);
    vector<ll> nums(n);
    vector<int> lastFactor(n);
    nums[0] = 1;

    priority_queue<plli, vector<plli>, greater<plli>> pq;
    for(int i = 0; i < len; ++i) {
      pq.push({primes[i], i});
    }

    for(int i = 1; i < n; ++i) {
      auto [num, index] = pq.top();
      pq.pop();

      nums[i] = num;
      lastFactor[i] = index;

      indice[index] += 1;
      while(lastFactor[indice[index]] > index) {
        indice[index] += 1;
      }
      pq.push({nums[indice[index]] * primes[index], index});
    }
    return nums.back();
  }
};

// Accepted
// 85/85 cases passed (264 ms)
// Your runtime beats 98.78 % of cpp submissions
// Your memory usage beats 15.18 % of cpp submissions (23.5 MB)
// @lc code=end
