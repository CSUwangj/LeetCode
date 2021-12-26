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
  int parent[30000] = {};

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
  }
public:
  bool gcdSort(vector<int>& nums) {
    int mmax = *max_element(nums.begin(), nums.end());
    map<int, vector<int>> pos;
    set<int> visit;
    int len = nums.size();
    vector<int> indice(len);
    for(int i = 0; i < len; ++i) {
      pos[nums[i]].push_back(i);
      indice[i] = i;
      parent[i] = i;
    }

    for(int i = 2; i <= mmax; ++i) {
      if(visit.count(i)) continue;
      int last = -1;
      for(int j = i; j <= mmax; j += i) {
        visit.insert(j);
        if(pos[j].empty()) continue;
        for(auto p : pos[j]) {
          if(last != -1) {
            merge(last, p);
          }
          last = p;
        }
      }
    }

    sort(indice.begin(), indice.end(), [&](int ia, int ib) {
      return nums[ia] < nums[ib];
    });
    for(int i = 0; i < len; ++i) {
      if(find(i) != find(indice[i])) return false;
    }
    return true;
  }
};

// Time Limit Exceeded
// 89/89 cases passed (N/A)
// @lc code=end
