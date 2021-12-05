/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  unordered_map<string, int> id;
  vector<string> id2string;
  unordered_map<int, string> name;
  
  vector<int> parent;
  
  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }
  
  void merge(int x, int y) {
    parent[find(y)] = find(x);
  }
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int count = 0;
    for(auto &account : accounts) {
      for(int i = 1; i < account.size(); ++i) {
        if(!id.count(account[i])) {
          id[account[i]] = count++;
          id2string.push_back(account[i]);
        }
      }
      name[id[account[1]]] = account[0];
    }
    parent.resize(count);
    for(int i = 0; i < count; ++i) parent[i] = i;
    for(auto &account : accounts) {
      for(int i = 2; i < account.size(); ++i) {
        merge(id[account[1]], id[account[i]]);
      }
    }
    vector<vector<string>> answer;
    unordered_map<int, vector<int>> tmp;
    for(int i = 0; i < count; ++i) {
      tmp[find(i)].push_back(i);
    }
    for(auto [root, mails] : tmp) {
      vector<string> account{name[root]};
      for(auto id : mails) account.push_back(id2string[id]);
      sort(account.begin() + 1, account.end());
      answer.push_back(account);
    }
    return move(answer);
  }
};

// Accepted
// 50/50 cases passed (72 ms)
// Your runtime beats 95.46 % of cpp submissions
// Your memory usage beats 75.75 % of cpp submissions (35.1 MB)
// @lc code=end
