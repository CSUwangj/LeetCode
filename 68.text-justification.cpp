/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
  string output_line(const vector<string> &line, int curLength, int maxWidth) {
    string result = line.front();
    if(line.size() == 1) {
      while(curLength++ < maxWidth) result.push_back(' ');
      return result;
    }
    int spaces = maxWidth - curLength;
    int rest = spaces % (line.size() - 1);
    int space = spaces / (line.size() - 1);
    for(int i = 1; i < line.size(); ++i) {
      for(int s = 0; s < space; ++s) result.push_back(' ');
      if(rest) {
        result.push_back(' ');
        rest -= 1;
      }
      result += line[i];
    }
    return result;
  }
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> answer;
    vector<string> line;
    int curLength = 0;
    for(auto word : words) {
      if(curLength + line.size() + word.length() > maxWidth) {
        answer.push_back(output_line(line, curLength, maxWidth));
        line.clear();
        curLength = 0;
      }
      curLength += word.length();
      line.emplace_back(word);
    }
    string lastLine = line.front();
    for(int i = 1; i < line.size(); ++i) {
      lastLine.push_back(' ');
      lastLine += line[i];
    }
    while(lastLine.length() < maxWidth) lastLine.push_back(' ');
    answer.push_back(lastLine);
    return answer;
  }
};

// Accepted
// 27/27 cases passed (3 ms)
// Your runtime beats 53 % of cpp submissions
// Your memory usage beats 50.56 % of cpp submissions (7.5 MB)
// @lc code=end
