/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
class Solution {
  unordered_map<string, vector<string>> mapping;
  void parsePath(string &path) {
    int pos = 0;
    int len = path.length();
    while(pos < len && path[pos] != ' ') pos += 1;
    string base = path.substr(0, pos);
    pos += 1;
    // cout << base << endl;
    while(pos < len) {
      int file = 0;
      while(path[pos + file] != '(') file += 1;
      string fileName = path.substr(pos, file);
      pos += file + 1;
      int content = 0;
      while(path[pos + content] != ')') content += 1;
      string contentString = path.substr(pos, content);
      // cout << fileName << " " << contentString << endl;
      mapping[contentString].push_back(base + "/" + fileName);
      pos += content + 2;
    }
  }
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    for(auto &path : paths) parsePath(path);
    vector<vector<string>> answer;
    for(auto &[content, files] : mapping) {
      if(files.size() > 1) answer.push_back(files);
    }
    return answer;
  }
};
// @lc code=end

