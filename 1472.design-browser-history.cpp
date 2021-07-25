/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory {
  string homepage;
  vector<string> history;
  int index = 1;
public:
  BrowserHistory(string _homepage): homepage(_homepage) {
    history.push_back(homepage);
  }
  
  void visit(string url) {
    while(history.size() > index) history.pop_back();
    history.push_back(url);
    index += 1;
  }
  
  string back(int steps) {
    if(index > steps) index = index - steps;
    else index = 1;
    return history[index - 1];
  }
  
  string forward(int steps) {
    if(index + steps > history.size()) index = history.size();
    else index += steps;
    return history[index - 1];
  }
};

// Accepted
// 71/71 cases passed (112 ms)
// Your runtime beats 94.89 % of cpp submissions
// Your memory usage beats 61.84 % of cpp submissions (57.6 MB)
// @lc code=end

