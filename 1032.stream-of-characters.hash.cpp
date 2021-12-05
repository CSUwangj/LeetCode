/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
using ll = long long;
const int SZ = 40000;
// ll p1[SZ];
const ll P1 = 29;
const ll MOD1 = 1e9 + 7;
constexpr auto p1 = []() {
  array<int, 40000> p1{1};
  for(int i = 1; i < SZ; ++i) {
    p1[i] = p1[i - 1] * P1 % MOD1;
  }
  return p1;
}();
class StreamChecker {
  vector<ll> hashes{0};
  // vector<ll> hash2;
  int sz = 0;
  vector<pair<int, int>> wordHashes;
  bool q() {
    for(const auto &[len, h] : wordHashes) {
      if(len > sz) continue;
      int suffixHash = ((hashes[sz] - hashes[sz - len] * p1[len]) % MOD1 + MOD1) % MOD1;
      // cout << hashes[sz] << ' ' << hashes[sz - len] << ' '<< p1[len] << endl;
      if(suffixHash == h) return true;
    }
    return false;
  }
public:
  StreamChecker(vector<string>& words) {
    for(const auto &word : words) {
      ll hash = 0;
      for(auto c : word) {
        hash = (hash * P1 + c - 'a') % MOD1;
      }
      wordHashes.push_back({word.length(), int(hash)});
    }
  }
  
  bool query(char letter) {
    int h = (hashes[sz] * P1 + letter - 'a') % MOD1;
    hashes.push_back(h);
    sz += 1;
    return q();
  }
};

// Accepted
// 17/17 cases passed (1140 ms)
// Your runtime beats 6.79 % of cpp submissions
// Your memory usage beats 99.32 % of cpp submissions (91 MB)
// @lc code=end
