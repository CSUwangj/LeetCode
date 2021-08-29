/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 */

// @lc code=start
class Complex {
private:
  int real;
  int imag;
public:
  Complex() : real(0), imag(0) {}
  Complex(string s): real(0), imag(0) {
    int pos = 0;
    bool realNegative = false;
    bool imagNegative = false;
    if(s[pos] == '-') {
      realNegative = true;
      pos += 1;
    }
    while(s[pos] != '+') {
      real *= 10;
      real += s[pos++] - '0';
    }
    pos += 1;
    if(s[pos] == '-') {
      imagNegative = true;
      pos += 1;
    }
    while(s[pos] != 'i') {
      imag *= 10;
      imag += s[pos++] - '0';
    }
    if(realNegative) real *= -1;
    if(imagNegative) imag *= -1;
  }
  string to_string() {
    bool realNegative = false;
    bool imagNegative = false;
    int real = this->real;
    int imag = this->imag;
    if(real < 0) {
      real = -real;
      realNegative = true;
    }
    if(imag < 0) {
      imag = -imag;
      imagNegative = true;
    }
    string result{'i'};
    if(imag) {
      while(imag) {
        result.push_back(imag % 10 + '0');
        imag /= 10;
      }
    } else {
      result.push_back('0');
    }
    if(imagNegative) result.push_back('-');
    result.push_back('+');
    if(real) {
      while(real) {
        result.push_back(real % 10 + '0');
        real /= 10;
      } 
    } else {
      result.push_back('0');
    }
    if(realNegative) result.push_back('-');
    reverse(result.begin(), result.end());
    return result;
  }
  Complex operator*(const Complex& b) {
    Complex result;
    result.real =  this->real * b.real - this->imag * b.imag;
    result.imag = this->imag * b.real + b.imag * this->real;
    return result;
  }
  // friend ostream & operator<<(ostream &os, const Complex &a);
};
// ostream & operator<<(ostream &os, const Complex &a) {
//   os << '(' << a.real << ',' << a.imag << ')';
//   return os;
// }
class Solution {
public:
  string complexNumberMultiply(string num1, string num2) {
    Complex n1(num1), n2(num2);
    // cout << n1.to_string() << ' ' << n2.to_string() << endl;
    // cout << n1 << ' ' << n2 << endl;
    auto result = n1 * n2;
    return result.to_string();
  }
};

// Accepted
// 55/55 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 62.22 % of cpp submissions (6 MB)
// @lc code=end

