/*
 * @lc app=leetcode id=1169 lang=cpp
 *
 * [1169] Invalid Transactions
 */

// @lc code=start
struct Transaction {
  int amount;
  int time;
  string city;
  string name;
  Transaction(int _time = 0, int _amount = 0, string _city = "") : amount(_amount), time(_time), city(_city) {}
  Transaction(string trans) {
    int len = trans.length();
    int pos = 0;
    while(trans[pos] != ',') pos += 1;
    name = trans.substr(0, pos);
    time = 0;
    pos += 1;
    while(trans[pos] != ',') {
      time *= 10;
      time += trans[pos] - '0';
      pos += 1;
    }
    amount = 0;
    pos += 1;
    while(trans[pos] != ',') {
      amount *= 10;
      amount += trans[pos] - '0';
      pos += 1;
    }
    pos += 1;
    city = trans.substr(pos);
  }
  string to_string() {
    return name + "," + ::to_string(time) + "," + ::to_string(amount) + "," + city;
  }
  bool operator<(const Transaction& another) const { return this->time < another.time; }
};

class Solution {
  unordered_map<string, vector<Transaction>> transactions;
public:
  vector<string> invalidTransactions(vector<string>& transactionStrings) {
    for(auto &tx : transactionStrings) {
      auto transaction = Transaction(tx);
      transactions[transaction.name].push_back(transaction);
    }
    vector<string> answer;
    for(auto &[name, transactions] : transactions) {
      int len = transactions.size();
      sort(transactions.begin(), transactions.end());
      vector<bool> invalid(len);
      for(int i = 0; i < len; ++i) {
        // cout << transactions[i].to_string() << endl;
        bool ok = true;
        for(int j = i - 1; j >= 0 && transactions[i].time - transactions[j].time <= 60; --j) {
          if(transactions[i].city != transactions[j].city) {
            invalid[j] = true;
            ok = false;
          }
        }
        if(!ok || transactions[i].amount > 1000) invalid[i] = true;
      }
      for(int i = 0; i < len; ++i) {
        if(invalid[i]) answer.push_back(transactions[i].to_string());
      }
    }
    return answer;
  }
};

// Accepted
// 36/36 cases passed (20 ms)
// Your runtime beats 87.55 % of cpp submissions
// Your memory usage beats 75.97 % of cpp submissions (13.3 MB)
// @lc code=end

