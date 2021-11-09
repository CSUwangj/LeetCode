/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
const int MOD = 10000;
inline void ltrim(string &s) {
  s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
    return ch != '0';
  }));
}
class BigInt {
  vector<int> digits;
public:
  BigInt(vector<int> digits = {}) noexcept : digits(move(digits)) {}
  BigInt(string &num) {
    int count = 0;
    int digit = 0;
    reverse(num.begin(), num.end());
    while(num.length() % 4) num.push_back('0');
    reverse(num.begin(), num.end());
    for(auto c : num) {
      digit *= 10;
      digit += c - '0';
      count += 1;
      if(count == 4) {
        digits.push_back(digit);
        digit = 0;
        count = 0;
      }
    }
    if(digit || digits.empty()) {
      digits.push_back(digit);
    }
    reverse(digits.begin(), digits.end());
  }

  BigInt operator+(const BigInt& other) const {
    int lenT = this->digits.size();
    int lenO = other.digits.size();
    int carry = 0;
    vector<int> results;
    int pos;
    for(pos = 0; pos < lenT && pos < lenO; ++pos) {
      cout << pos << endl;
      int result = this->digits[pos] + other.digits[pos] + carry;
      results.push_back(result % MOD);
      carry = result / MOD;
    }
    while(pos < lenT) {
      results.push_back(this->digits[pos]);
      pos += 1;
    }
    while(pos < lenO) {
      results.push_back(other.digits[pos]);
      pos += 1;
    }
    cout << pos << endl;
    pos = min(lenO, lenT);
    while(carry) {
      cout << pos << ' ' << carry << endl;
      if(results.size() <= pos) results.push_back(0);
      results[pos] += carry;
      carry = results[pos] / MOD;
      results[pos] %= MOD;
      pos += 1;
    }
    if(results.empty()) results.push_back(0);
    return BigInt(results);
  }

  BigInt operator*(const BigInt& other) const {
    int lenT = this->digits.size();
    int lenO = other.digits.size();
    int carry = 0;
    vector<int> results;
    for(int i = 0; i < lenT; ++i) {
      int carry = 0;
      for(int j = 0; j < lenO; ++j) {
        int result = this->digits[i] * other.digits[j] + carry;
        if(results.size() <= i + j) results.push_back(0);
        results[i + j] += result;
        carry = results[i + j] / MOD;
        results[i + j] %= MOD;
      }
      int pos = lenO;
      while(carry) {
        if(results.size() <= i + pos) results.push_back(0);
        results[i + pos] += carry;
        carry = results[i + pos] / MOD;
        results[i + pos] %= MOD;
        pos += 1;
      }
    }
    
    if(results.empty()) results.push_back(0);
    return BigInt(results);
  }
  
  string to_string() {
    string result;
    for(auto digit : digits) {
      for(int i = 0; i < 4; ++i) {
        result.push_back(digit % 10 + '0');
        digit /= 10;
      }
    }
    reverse(result.begin(), result.end());
    ltrim(result);
    if(result.empty()) result.push_back('0');
    return result;
  }
  
  friend ostream& operator<<(ostream &out, const BigInt &i) {
    for(auto it = i.digits.rbegin(); it != i.digits.rend(); ++it) {
      out << setfill('0') << setw(4)  << *it;
    }
    return out;
  }
};

class Solution {
public:
  string multiply(string num1, string num2) {
    BigInt a(num1), b(num2);
    return (a * b).to_string();
  }
};

// Accepted
// 311/311 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 37.23 % of cpp submissions (6.9 MB)
// @lc code=end

