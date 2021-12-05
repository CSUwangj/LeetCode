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
const int SZ = 40001;
// ll p1[SZ];
const ll P1 = 29;
const ll MOD1 = 1e9 + 7;
constexpr auto p1 = []() {
  array<int, SZ> p1{1};
  for(int i = 1; i < SZ; ++i) {
    p1[i] = p1[i - 1] * P1 % MOD1;
  }
  return p1;
}();
int hashes[SZ];
class StreamChecker {
  int sz = 0;
  map<int, set<int>> wordHashes;
  bool q() {
    for(const auto &[len, lenHashes] : wordHashes) {
      if(len > sz) break;
      int suffixHash = ((1LL * hashes[sz] - 1LL * hashes[sz - len] * p1[len]) % MOD1 + MOD1) % MOD1;
      // cout << hashes[sz] << ' ' << hashes[sz - len] << ' '<< p1[len] << endl;
      if(lenHashes.count(suffixHash)) return true;
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
      wordHashes[word.length()].insert(int(hash));
    }
  }
  
  bool query(char letter) {
    int h = (hashes[sz] * P1 + letter - 'a') % MOD1;
    hashes[++sz] = h;
    return q();
  }
};

// Accepted
// 17/17 cases passed (784 ms)
// Your runtime beats 14.71 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (88.1 MB)
// @lc code=end
