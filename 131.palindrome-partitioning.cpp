/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
    int len;
    vector<vector<bool>> isPalindrome;
    
    void init(string &s) {
        len = s.length();
        isPalindrome.resize(len+1, vector<bool>(len+1));
        for(int i = 0; i < len; ++i) {
            isPalindrome[i][i] = true;
            isPalindrome[i][i+1] = true;
        }
        for(int i = 2; i <= len; ++i) {
            for(int j = 0; j+i <= len; ++j) {
                isPalindrome[j][j+i] = isPalindrome[j+1][j+i-1] && (s[j] == s[j+i-1]);
            }
        }
    }
    
    void dfs(vector<vector<string>> &answer, vector<string> &container, string &s, int index) {
        if(index == len) {
            answer.push_back(container);
        }
        for(int i = 1; index+i <= len; ++i) {
            if(isPalindrome[index][index+i]) {
                container.push_back(s.substr(index, i));
                dfs(answer, container, s, index+i);
                container.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        init(s);
        vector<vector<string>> answer;
        vector<string> container;
        dfs(answer, container, s, 0);
        return answer;
    }
};
// @lc code=end

