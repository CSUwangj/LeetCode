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
    int n = *max_element(A.begin(), A.end());
    int st[n + 1];
    bool visit[n + 1];
    memset(visit, 0, sizeof(visit));
    memset(st, 0, sizeof(st));
    for(auto i : A) {
      st[i] = 1;
    }
    for(int i = 2; 2 * i <= n; ++i) {
      if(visit[i]) continue;
      int last = 0;
      for(int j = i; j <= n; j += i) {
        visit[j] = true;
        if(st[j]) {
          if(last) merge(last, j);
          last = j;
          // cout << i << ' ' << j << endl;
        }  
      }
    }
    int answer = 0;
    for(auto i : A) {
      answer = max(answer, ++count[find(i)]);
      // cout << i << ' ' << find(i) << endl;
    }
    return answer;
  }
};

// Accepted
// 104/104 cases passed (93 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 92.13 % of cpp submissions (32.8 MB)
// @lc code=end
