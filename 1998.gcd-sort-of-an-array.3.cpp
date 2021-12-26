/*
 * @lc app=leetcode id=1998 lang=cpp
 *
 * [1998] GCD Sort of an Array
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
  bool gcdSort(vector<int>& nums) {
    int mmax = *max_element(nums.begin(), nums.end());
    int parent[mmax + 1];
    memset(parent, 0, sizeof(parent));
    function<int(int)> find;
    find = [&](int x) {
      if(!parent[x]) parent[x] = x;
      if(parent[x] != x) parent[x] = find(parent[x]);
      return parent[x];
    };

    auto merge = [&](int x, int y) {
      x = find(x);
      y = find(y);
      parent[x] = y;
    };

    int len = nums.size();
    int pos = 0;

    for(auto n : nums) {
      int a = n;
      for(int i = 2; i * i <= a && !parent[a]; i += (1 + (i != 2))) {
        if(a % i == 0) {
          merge(n, i);
          while(a % i == 0) a /= i;
        }
      }
      if(a != 1) {
        merge(n, a);
      }
    }

    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    for(int i = 0; i < len; ++i) {
      cout << find(nums[i]) << ' ' << find(sortedNums[i]) << endl;
      if(find(nums[i]) != find(sortedNums[i])) return false;
    }
    return true;
  }
};

// Accepted
// 89/89 cases passed (160 ms)
// Your runtime beats 95.51 % of cpp submissions
// Your memory usage beats 90.20 % of cpp submissions (52.1 MB)
// @lc code=end
