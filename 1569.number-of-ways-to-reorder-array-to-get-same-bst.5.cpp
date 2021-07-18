/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

#define MOD 1000000007

constexpr int qpow(long long b, int e) {
  long long result = 1;
  while(e) {
    if(e & 1) {
      result = result * b % MOD;
    }
    b = b * b % MOD;
    e >>= 1;
  }
  return result;
}

int _i[1000];
int _c[1000][500];

constexpr int inv(int a) {
  if(_i[a]) return _i[a];
  return _i[a] = qpow(a, MOD - 2);
}
constexpr int C(int m, int n) {
  m = min(m, n - m);
  if(_c[n][m]) return _c[n][m];
  long long result = 1;
  for(int i = m + 1; i <= n; ++i) {
    result = result * i % MOD;
  }
  for(int i = 1; i <= n - m; ++i) {
    result = result * inv(i) % MOD;
  }
  _c[n][m] = result;
  return result;
}

class Solution {
  int len;
  long long answer;
  void solve(vector<int> &nums, int index, int leftBound, int rightBound) {
    int root = nums[index];
    // cout << root << ' ' << leftBound << ' ' << rightBound << endl;
    answer *= C(root - leftBound - 1, rightBound - leftBound - 2);
    answer %= MOD;
    bool needLeft = root - leftBound > 1;
    bool needRight = rightBound - root > 1;
    for(int i = index + 1; i < len && (needLeft || needRight); ++i) {
      if(needLeft && nums[i] < root && nums[i] > leftBound) {
        solve(nums, i, leftBound, root);
        needLeft = false;
      }
      if(needRight && nums[i] > root && nums[i] < rightBound) {
        solve(nums, i, root, rightBound);
        needRight = false;
      }
    }
  }
public:
  int numOfWays(vector<int>& nums) {
    len = nums.size();
    answer = 1;
    solve(nums, 0, 0, len + 1);
    return (answer + MOD - 1) % MOD;
  }
};

// Accepted
// 161/161 cases passed (28 ms)
// Your runtime beats 96.42 % of cpp submissions
// Your memory usage beats 95.59 % of cpp submissions (14.6 MB)
// @lc code=end

