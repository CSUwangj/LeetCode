/*
 * @lc app=leetcode id=1178 lang=cpp
 *
 * [1178] Number of Valid Words for Each Puzzle
 */

// @lc code=start
class Solution {
  int bitmask(const string &s) {
    int mask = 0;
    for(auto c : s) {
      mask |= (1 << (c - 'a'));
    }
    return mask;
  }
public:
  vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    unordered_map<int, int> count;
    for(auto &word : words) {
      sort(word.begin(), word.end());
      word.resize(unique(word.begin(), word.end()) - word.begin());
      count[bitmask(word)] += 1;
    }

    vector<int> answer;
    answer.reserve(puzzles.size());

    for(auto &puzzle : puzzles) {
      int first = (1 << (puzzle.front() - 'a'));
      int result = count[first];

      int mask = bitmask(puzzle.substr(1));
      for(int submask = mask; submask; submask = (submask - 1) & mask) {
        result += count[submask | first];
      }
      answer.push_back(result);
    }

    return answer;
  }
};

// Accepted
// 10/10 cases passed (176 ms)
// Your runtime beats 81.43 % of cpp submissions
// Your memory usage beats 61.43 % of cpp submissions (47.3 MB)
// @lc code=end

