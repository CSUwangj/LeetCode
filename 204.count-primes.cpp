/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
  int countPrimes(int n) {
    bool isPrime[n + 2];
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) {
      if(!isPrime[i]) continue;
      for(int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
    return accumulate(isPrime, isPrime + n, 0);
  }
};
// @lc code=end

