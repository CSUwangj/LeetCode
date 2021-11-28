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
  unordered_map<int, int> parent, count;
  
  int find(int x) {
    if(!parent.count(x)) parent[x] = x;
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
      for(int i = 2; i*i <= num; ++i) {
        if(num % i == 0) {
          merge(num, i);
          merge(num, num / i);
        }
      }
    }
    int answer = 0;
    for(auto i : A) answer = max(answer, ++count[find(i)]);
    return answer;
  }
};

// Accepted
// 104/104 cases passed (1056 ms)
// Your runtime beats 11.24 % of cpp submissions
// Your memory usage beats 69.29 % of cpp submissions (59.8 MB)
// @lc code=end
