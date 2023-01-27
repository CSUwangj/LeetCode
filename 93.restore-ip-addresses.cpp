/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}
class Solution {
  int len;
  int minmax[4][2] = {{}, {-1, 10}, {9, 100}, {99, 256}};
  void addIP(
    vector<string> &answer,
    vector<string> &currentIP
  ) {
    string ip;
    for(auto subnet : currentIP) {
      ip += subnet;
      ip.push_back('.');
    }
    ip.pop_back();
    answer.emplace_back(ip);
  }
  void dfs(
    vector<string> &answer,
    vector<string> &currentIP,
    string &s,
    int pos
  ) {
    if(pos == len) {
      if(currentIP.size() == 4) addIP(answer, currentIP);
      return;
    }
    for(int i = 1; i < 4 && pos + i <= s.length(); ++i) {
      string subnet = s.substr(pos, i);
      int n = stoi(subnet);
      if(n <= minmax[i][0]) break;
      if(n < minmax[i][1]) {
        currentIP.emplace_back(subnet);
        dfs(answer, currentIP, s, pos + i);
        currentIP.pop_back();
      }
    }
  }
public:
  vector<string> restoreIpAddresses(string s) {
    len = s.length();
    vector<string> answer;
    vector<string> ip;
    dfs(answer, ip, s, 0);
    return answer;
  }
};

// Accepted
// 145/145 cases passed (8 ms)
// Your runtime beats 19.08 % of cpp submissions
// Your memory usage beats 70.83 % of cpp submissions (6.6 MB)
// @lc code=end

