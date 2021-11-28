/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int parent[100001] = {};
  int count[100001] = {};
  
  int find(int x) {
    if(!parent[x]) parent[x] = x;
    else if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }
  
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
  }
public:
  int largestComponentSize(vector<int>& A) {
    for(auto num : A) {
      int prev = num;
      for(int i = 2; i*i <= num; ++i) {
        if(num % i == 0) {
          merge(prev, i);
          prev = i;
          while(num % i == 0) {
            num /= i;
          }
        }
      }
      if(num > 1) {
        merge(prev, num);
      }
    }
    int answer = 0;
    for(auto i : A) answer = max(answer, ++count[find(i)]);
    return *max_element(count, count + 100001);
  }
};

// Accepted
// 104/104 cases passed (182 ms)
// Your runtime beats 89.14 % of cpp submissions
// Your memory usage beats 99.25 % of cpp submissions (31.9 MB)
// @lc code=end
