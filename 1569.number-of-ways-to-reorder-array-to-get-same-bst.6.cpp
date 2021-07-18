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

int c[1000][500];
auto speed2 = [](){
  for(int i = 0; i < 1000; i++) {
    c[i][0] = 1;
    for(int j = 1; 2 * j <= i; ++j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j * 2 <= i - 1 ? j : i - 1 - j]) % MOD;
      // cout << i << " " << j << ' ' << c[i][j] << endl;
    }
  }
  return 1;
}();

class Solution {
  int len;
  long long answer;
  void solve(vector<int> &nums, int index, int leftBound, int rightBound) {
    int root = nums[index];
    // cout << root << ' ' << leftBound << ' ' << rightBound << ' ' ;
    int n = rightBound - leftBound - 2;
    int m = root - leftBound - 1;
    m = min(m, n - m);
    answer *= c[n][m];
    answer %= MOD;
    // cout << answer << endl;
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
// 161/161 cases passed (24 ms)
// Your runtime beats 97 % of cpp submissions
// Your memory usage beats 96.19 % of cpp submissions (14.6 MB)
// @lc code=end

